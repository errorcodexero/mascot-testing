var canvas = document.getElementById("design");
var ctx = canvas.getContext("2d");

console.clear();

const WIDTH = 16;
const HEIGHT = 12;

var f = 0;

var mouse_down = false;
var in_grid = false;
var grid_x = 0, grid_y = 0;

var pick_primed = false;
var fill_primed = false;
var rect_stage = 0;

cleanNode(document.body);

function toHex(n) {
	return ("0" + n.toString(16)).slice(-2);
}

class Color {
	constructor(r, g, b) {
		this.r = r;
		this.g = g;
		this.b = b;
	}

	copy() {
		return new Color(this.r, this.g, this.b);
	}

	hex() {
		return "#" + toHex(this.r) + toHex(this.g) + toHex(this.b);
	}

	display_color() {
		var CHANNEL_MIN = 25;
		var new_r = Math.max(this.r, CHANNEL_MIN);
		var new_g = Math.max(this.g, CHANNEL_MIN);
		var new_b = Math.max(this.b, CHANNEL_MIN);
		return new Color(new_r, new_g, new_b).hex();
	}

	inverse() {
		return new Color(255 - this.r, 255 - this.g, 255 - this.b);
	}

	name() {
		return color_map.get(this.hex());
	}

	equals(c) {
		return this.r == c.r && this.g == c.g && this.b == c.b;
	}
}
var selected_color = new Color(255, 0, 0);

function hexToColor(hex) {
	return new Color(parseInt(hex.substr(1,2), 16), parseInt(hex.substr(3,2), 16), parseInt(hex.substr(5,2), 16));
}

function rgbToColor(rgb) {
	var split = rgb.substring(rgb.indexOf("(") + 1, rgb.indexOf(")")).split(",").map(x => x.trim());
	return new Color(split[0], split[1], split[2]);
}

var named_colors = document.getElementById("named_colors");
var picker_button = document.getElementById("picker_button");
for (var c of color_map.keys()) {
	var button = document.createElement("button");
	button.style.backgroundColor = c;
	button.setAttribute("onclick", "selected_color = hexToColor('" + c + "')");

	var color = hexToColor(c);

	var close_to_black = Math.sqrt(Math.pow(color.r, 2) + Math.pow(color.g, 2) + Math.pow(color.b, 2)) < 220;
	button.style.color = close_to_black ? "white" : "black";
	button.setAttribute("onmouseenter", "this.style.color = '" + (close_to_black ? "black" : "white") + "'");
	button.setAttribute("onmouseleave", "this.style.color = '" + (close_to_black ? "white" : "black") + "'");

	var name_parts = color_map.get(c).toLowerCase().split("_");
	for (var i = 0; i < name_parts.length; i++) {
		name_parts[i] = name_parts[i].charAt(0).toUpperCase() + name_parts[i].slice(1);
	}
	button.innerHTML = name_parts.join(" ");

	named_colors.insertBefore(button, picker_button);
}

function createDefaultColor() {
	return new Color(0, 0, 0);
}

function createBlankArray(len) {
	return new Array(len).fill().map(x => createDefaultColor());
}

function createBlankFrame() {
	return new Array(HEIGHT).fill().map(x => createBlankArray(WIDTH));
}

var screen = [createBlankFrame()];

var overflow;
function resetOverflow() {
	overflow = {
		top: [],
		bottom: [],
		right: [],
		left: []
	};
}
resetOverflow();

function updatePickerColor() {
	var r  = document.getElementById("red_slider").value;
	document.getElementById("red_label").innerHTML = r;
	var g = document.getElementById("green_slider").value;
	document.getElementById("green_label").innerHTML = g;
	var b = document.getElementById("blue_slider").value;
	document.getElementById("blue_label").innerHTML = b;
	document.getElementById("custom").style.backgroundColor = "rgb(" + r + ", " + g + ", " + b + ")";
}

function updateHexInputColor() {
	var input = prompt('Input hex code:');
	selected_color = hexToColor(input);
	document.getElementById("hex").style.backgroundColor = selected_color.hex();
}

function copyArray(arr) {
	if (!Array.isArray(arr)) {
		return arr;
	}

	var new_arr = new Array();
	for (var i = 0; i < arr.length; i++) {
		new_arr.push(copyArray(arr[i]));
	}
	return new_arr;
}

function updateFrameLabel() {
	var slider = document.getElementById("frame_slider");
	slider.max = screen.length;
	slider.value = f + 1;
	document.getElementById("frame_label").innerHTML = (f+1) + "/" + screen.length;
}

function addFrame(){
	f++;
	screen.splice(f, 0, createBlankFrame());
	updateFrameLabel();
}

function cloneFrame(){
	f++;
	screen.splice(f, 0, copyArray(screen[f - 1]));
	updateFrameLabel();
}

function deleteFrame(){
	if (screen.length > 1) {
		screen.splice(f, 1);
		if (f > screen.length - 1) {
			f = screen.length - 1; 
		}
		updateFrameLabel();
	}
}

function updateFrame() {
	f = document.getElementById("fSl").value - 1;
	updateFrameLabel();
}

function nextFrame() {
	if (f < screen.length - 1) {
		f++;
		resetOverflow();
		updateFrameLabel();
	}
}

function lastFrame() {
	if (f > 0) {
		f--;
		resetOverflow();
		updateFrameLabel();
	}
}

function shiftOverflowNext(side) {
	overflow[side].forEach(x => {
		x.splice(0, 0, createDefaultColor());
		x.length--;
	});
}

function shiftOverflowPrev(side) {
	overflow[side].forEach(x => {
		x.shift();
		x[WIDTH - 1] = createDefaultColor();
	});
}

function shiftFrameLeft(){
	var new_frame = new Array();

	var right_overflow = overflow.right.length > 0 ? copyArray(overflow.right.pop()) : createBlankArray(HEIGHT);
	for (i = 0; i < HEIGHT; i++) {
		new_frame[i] = new Array();
		for (j = 1; j < WIDTH; j++) {
			new_frame[i][j - 1] = copyArray(screen[f][i][j]);
		}
		new_frame[i][WIDTH - 1] = right_overflow[i];
	}

	overflow.left.push([]);
	screen[f].map((x, i) => overflow.left[overflow.left.length - 1][i] = x[0]);
	
	shiftOverflowPrev("top");
	shiftOverflowPrev("bottom");
	
	screen[f] = new_frame;
}

function shiftFrameRight(){
	var new_frame = new Array();

	var left_overflow = overflow.left.length > 0 ? copyArray(overflow.left.pop()) : createBlankArray(HEIGHT);
	for (i = 0; i < HEIGHT; i++) {
		new_frame[i] = new Array();
		for (j = 0; j < WIDTH - 1; j++) {
			new_frame[i][j + 1] = copyArray(screen[f][i][j]);
		}
		new_frame[i][0] = left_overflow[i];
	}

	overflow.right.push([]);
	screen[f].map((x, i) => overflow.right[overflow.right.length - 1][i] = x[WIDTH - 1]);

	shiftOverflowNext("top");
	shiftOverflowNext("bottom");
	
	screen[f] = new_frame;
}

function shiftFrameUp(){
	var new_frame = new Array();

	for (i = 1; i < HEIGHT; i++) {
		new_frame[i - 1] = copyArray(screen[f][i]);
	}	
	var bottom_overflow = overflow.bottom.length > 0 ? copyArray(overflow.bottom.pop()) : createBlankArray(WIDTH);
	new_frame[HEIGHT - 1] = bottom_overflow;

	overflow.top.push([]);
	screen[f][0].map((x, i) => overflow.top[overflow.top.length - 1][i] = x);

	shiftOverflowPrev("left");
	shiftOverflowPrev("right");

	screen[f] = new_frame;
}

function shiftFrameDown(){
	var new_frame = new Array();

	for (i = 0; i < HEIGHT - 1; i++) {
		new_frame[i + 1] = copyArray(screen[f][i]);
	}
	var top_overflow = overflow.top.length > 0 ? copyArray(overflow.top.pop()) : createBlankArray(WIDTH);
	new_frame[0] = top_overflow;

	overflow.bottom.push([]);
	screen[f][HEIGHT - 1].map((x, i) => overflow.bottom[overflow.bottom.length - 1][i] = x);

	shiftOverflowNext("right");
	shiftOverflowNext("left");
	
	screen[f] = new_frame;
}

function outputJSArray() {
	var display = "[";
	for (a = 0; a < screen.length; a++) {
		display += "\n\t[";
		for (i = 0; i < screen[0].length; i++) {
			display += "\n\t\t[";
			for (j = 0; j < screen[0][0].length; j++) {
				display += "[\"" + screen[a][i][j].hex().substring(1,3) + "\", \"" + screen[a][i][j].hex().substring(3,5) + "\", \"" + screen[a][i][j].hex().substring(5,7) + "\"]";
				if (j != screen[0][0].length - 1) display += ", ";
			}
			display += "]";
			if (i != screen[0].length - 1) display += ",";
		}
		display += "\n\t]";
		if (a != screen.length - 1) display += ",";
	}
	display += "\n]";
	document.getElementById("designer_display").value = display;
}

function inputJSArray() {
	var input = prompt("Paste array");
	console.log(screen);
	eval("var js_input = " + input + ";");
	js_input.forEach((x, i) =>
		x.forEach((y, j) =>
			y.forEach((z, k) => screen[i][j][k] = hexToColor(z))
		)
	);
	if (f > screen.length - 1) {
		f = screen.length - 1; 
		updateFrameLabel();
	}
	console.log(screen);
}

function outputCArray() {
	var display = "";
	for (a = 0; a < screen.length; a++) {
		display += "{\n";
		for (i = 0; i < screen[a].length; i++) {
			display += "\t";
			for (j = 0; j < screen[a][i].length; j++) {
				display += "Color_index::" + screen[a][i][j].name();
				if (i != screen[a].length - 1 || j != screen[a][i].length - 1) display += ", ";
			}
			display += "\n";
		}
		display += "},\n";
	}
	document.getElementById("designer_display").value = display;
}

setInterval(draw, 50);

function draw() {
	ctx.fillStyle = "#000";
	ctx.fillRect(0, 0, 800, 600);
	
	if (in_grid) {
		ctx.fillStyle = screen[f][grid_y][grid_x].inverse().display_color();
		ctx.beginPath();
		ctx.arc(25 + 50 * grid_x, 25 + 50 * grid_y, 13, 0, 2 * Math.PI, false);
		ctx.fill();
	}

	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			ctx.fillStyle = screen[f][i][j].display_color();
			ctx.beginPath();
			ctx.arc(25 + 50 * j, 25 + 50 * i, 10, 0, 2 * Math.PI, false);
			ctx.fill();
		}
	}
	
	canvas.style.border = "5px solid " + selected_color.hex();
}

function resetCursor() {
	canvas.style.cursor = "default";
}

function primePick() {
	if (!pick_primed) {
		pick_primed = true;
		fill_primed = false;
		rect_stage = 0;
		canvas.style.cursor = "url('dropper_cursor.png'), pointer";
	} else {
		pick_primed = false;
		resetCursor();
	}
}

function primeFill() {
	if (!fill_primed) {
		fill_primed = true;
		pick_primed = false;
		rect_stage = 0;
		canvas.style.cursor = "url('paint_cursor.png'), pointer";
	} else {
		fill_primed = false;
		resetCursor();
	}
}

function primeRect() {
	if (rect_stage == 0) {
		rect_stage = 1;
		fill_primed = false;
		pick_primed = false;
		canvas.style.cursor = "se-resize";
	} else {
		rect_stage = 0;
		resetCursor();
	}
}

function Point(x, y) {
	this.x = x;
	this.y = y;
}

var fill_crawlers = [];
var fill_initial_color;
var fill_crawl_interval;
function trySpawnCrawler(x, y, new_crawlers) {
	var in_bounds = x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
	if (in_bounds && fill_initial_color.equals(screen[f][y][x])) {
		screen[f][y][x] = selected_color.copy();
		new_crawlers.push(new Point(x, y));
	}
}

function updateCrawlers() {
	var new_crawlers = [];

	fill_crawlers.forEach(x => {
		trySpawnCrawler(x.x + 1, x.y, new_crawlers);
		trySpawnCrawler(x.x - 1, x.y, new_crawlers);
		trySpawnCrawler(x.x, x.y + 1, new_crawlers);
		trySpawnCrawler(x.x, x.y - 1, new_crawlers);
	});

	if (new_crawlers.length == 0) {
		clearInterval(fill_crawl_interval);
	} else {
		fill_crawlers = new_crawlers;
	}
}

var rect_initial_pt;

function updateMousePos(e) {
	var rect = canvas.getBoundingClientRect();
	var mouse_x = Math.round((e.clientX - rect.left));
	var mouse_y = Math.round((e.clientY - rect.top));

	if (mouse_x > 0 && mouse_x < 800 && mouse_y > 0 && mouse_y < 600) {
		in_grid = true;
		grid_x = Math.round((mouse_x - 25) / 50);
		grid_y = Math.round((mouse_y - 25) / 50);
	} else {
		in_grid = false;
	}
}

function tryColorCell() {	
	if (in_grid) {
		if (pick_primed) {
			selected_color = screen[f][grid_y][grid_x].copy();
			resetCursor();
			pick_primed = false;
		} else if (fill_primed) {
			fill_initial_color = screen[f][grid_y][grid_x].copy();
			fill_crawl_interval = setInterval(updateCrawlers, 10);
			fill_crawlers = [new Point(grid_x, grid_y)];
			resetCursor();
			fill_primed = false;
		} else if (rect_stage == 1) {
			rect_initial_pt = new Point(grid_x, grid_y);
			canvas.style.cursor = "nw-resize";
			rect_stage = 2;
		} else if (rect_stage == 2) {
			for (var i = rect_initial_pt.y; i < grid_y + 1; i++) {
				for (var j = rect_initial_pt.x; j < grid_x + 1; j++) {
					screen[f][i][j] = selected_color.copy();
				}
			}
			resetCursor();
			rect_stage = 0;
		} else {
			screen[f][grid_y][grid_x] = selected_color.copy();
		}
	}
}

document.onmousemove = function(e) {	
	e = window.event || e;
	updateMousePos(e);
	if (mouse_down) tryColorCell();
}

document.onmousedown = function(e) {
	e = window.event || e;
	updateMousePos(e);
	tryColorCell();
    mouse_down = true;
}

document.onmouseup = function(e) {
    e = window.event || e;
    mouse_down = false;
}
