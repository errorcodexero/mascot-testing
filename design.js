var canvas = document.getElementById("design");
var ctx = canvas.getContext("2d");

console.clear();

const WIDTH = 16;
const HEIGHT = 12;

var f = 0;
var color = "#ff0000";

var mouse_down = false;
var picking = false;

function createDefaultColor() {
	return ["11", "11", "11"];
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

function toHex(n) {
	return ("0" + parseInt(n).toString(16)).slice(-2);
}

function updatePickerColor() {
	var r  = document.getElementById("rSl").value;
	document.getElementById("rLabel").innerHTML = r;
	var g = document.getElementById("gSl").value;
	document.getElementById("gLabel").innerHTML = g;
	var b = document.getElementById("bSl").value;
	document.getElementById("bLabel").innerHTML = b;
	document.getElementById("custom").style.backgroundColor = "rgb(" + r + ", " + g + ", " + b + ")";
}

function updateHexInputColor() {
	var input = prompt('Input hex code:');
	color = input;
	document.getElementById("hex").style.backgroundColor = input;
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
	var slider = document.getElementById("fSl");
	slider.max = screen.length;
	slider.value = f + 1;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" + (f+1) + "/" + document.getElementById("fSl").max;
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
		display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;[";
		for (i = 0; i < screen[0].length; i++) {
			display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[";
			for (j = 0; j < screen[0][0].length; j++) {
				display += '["' + screen[a][i][j].join('","') + '"]';
				if (j != screen[0][0].length - 1) display += ", ";
			}
			display += "]";
			if (i != screen[0].length - 1) display += ",";
		}
		display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;]";
		if (a != screen.length - 1) display += ",";
	}
	display +="<br/>]";
	document.getElementById("display").innerHTML = display;
}

function inputJSArray() {
	var input = prompt("Paste array");
	eval("screen = " + input + ";");
	if (f > screen.length - 1) {
		f = screen.length - 1; 
		updateFrameLabel();
	}
}

function outputCArray() {
	var display = "";
	for (a = 0; a < screen.length; a++) {
		display += "{<br/>";
		for (i = 0; i < screen[a].length; i++) {
			display += "&nbsp;&nbsp;&nbsp;&nbsp;";
			for (j = 0; j < screen[a][i].length; j++) {
				display += "Color_index::" + colors.get(screen[a][i][j].join());
				if (i != screen[a].length - 1 || j != screen[a][i].length - 1) display += ", ";
			}
			display += "<br/>";
		}
		display += "},<br/>";
	}
	document.getElementById("display").innerHTML = display;
}

setInterval(draw, 50);

function draw() {
	ctx.fillStyle = "#000";
	ctx.fillRect(0, 0, 800, 600);
	
	for (i = 0; i < HEIGHT; i++) {
		for (j = 0; j < WIDTH; j++) {
			ctx.fillStyle = arrayToHTMLColor(screen[f][i][j]);
			ctx.beginPath();
			ctx.arc(25 + 50 * j, 25 + 50 * i, 10, 0, 2 * Math.PI, false);
			ctx.fill();
		}
	}
	
	//document.getElementById("design").style.border = "5px solid "+color+";";
}

function tryColorCell(e) {
	e = window.event || e;

	var rect = canvas.getBoundingClientRect();
	var mouse_x = Math.round((e.clientX - rect.left));
	var mouse_y = Math.round((e.clientY - rect.top));

	if (mouse_x > 0 && mouse_x < 800 && mouse_y > 0 && mouse_y < 600) {
		var x = Math.round((mouse_x - 25) / 50);
		var y = Math.round((mouse_y - 25) / 50);
		if (color.startsWith("#")) {	
			screen[f][y][x][0] = color.substr(1,2);
			screen[f][y][x][1] = color.substr(3,2);
			screen[f][y][x][2] = color.substr(5,2);
		} else {
			var split = color.substring(color.indexOf("(") + 1, color.indexOf(")")).split(",").map(x => x.trim());
			split.forEach((c, i) => screen[f][y][x][i] = toHex(c));
		}
	}
}

document.onmousemove = function(e) {	
	if (mouse_down) tryColorCell(e);
}

document.onmousedown = function(e) {
	tryColorCell(e);
    mouse_down = true;
}

document.onmouseup = function(e) {
    e = window.event || e;
    mouse_down = false;
}
