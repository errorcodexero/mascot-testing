var canvas = document.getElementById("testing");
var ctx = (canvas != null) ? canvas.getContext("2d") : null;

console.clear();

var n_files = 0;

var designs = {};
var current_design = "smile";

var modes_container = document.getElementById("modes");

var DRAW_DELAY = 200;
var draw_interval;

function Category(name, color, border_color, contents) {
	n_files += contents.length;
	this.contents = contents;

	this.element = document.createElement("div");
	this.element.setAttribute("class", "category");
	this.element.style.backgroundColor = color;
	this.element.style.borderColor = border_color;
	modes_container.appendChild(this.element);

	var header = document.createElement("h4");
	header.innerHTML = name;
	this.element.appendChild(header);

	for (var i = 0; i < this.contents.length; i++) {
		designs[this.contents[i]] = {
			category: this
		};

		var filename = "designs/" + this.contents[i] + ".js";
		var design_script = document.createElement("script");
		design_script.setAttribute("src", filename);
		design_script.onload = addLoaded;
		document.head.appendChild(design_script);
	}
}

var files = {
	dial_0: new Category("Dial Position 0", "#AFF", "#3FF", [
		"smile",
		"neutral",
		"frown",
		"space",
		"fire",
		"team",
		"tron",
		"pacman",
		"first"
	]),
	dial_1: new Category("Dial Position 1", "#FAF", "#F3F", [
		"surprise",
		"slide",
		"pong",
		"alert",
		"star",
		"blue",
		"red",
		"matrix",
		"wheel",
		"tetris"
	]),
	dial_2: new Category("Dial Position 2", "#FFA", "#FF3", [
		"cube",
		"wave",
		"charging",
		"portal",
		"aperture",
		"vvvvvv",
		"wink",
		"color_bars",
		"pokeball",
		"maze"
	]),
	unused: new Category("Unused", "#FAA", "#F33", [
		"bear_2046",
		"bear_metal",
		"box_flame",
		"flux",
		"game_of_life",
		"i_heart_robots",
		"phoenix",
		"playoffs",
		"saw_wave",
		"scroll_1425",
		"spin",
		"square_wave",
		"triangle_wave",
		"two_waves",
		"woah"
	])
};

var loaded = 0;
function addLoaded() {
	loaded++;
	if (loaded == n_files) {
		setupDesigns();
		draw_interval = (ctx != null) ? setInterval(draw, DRAW_DELAY) : null;
	}
}

function setupDesigns() {	
	for (var d in designs) {
		if (designs[d].name == null) {
			name_parts = d.split("_");
			for (var i = 0; i < name_parts.length; i++) {
				name_parts[i] = name_parts[i].charAt(0).toUpperCase() + name_parts[i].slice(1);
			}
			designs[d].name = name_parts.join(" ");
		}

		var container = document.createElement("div");
		container.setAttribute("class", "design_container");
		designs[d].category.element.appendChild(container);

		var button = document.createElement("button");
		button.setAttribute("onclick", "setDesign(\"" + d + "\")");
		button.innerHTML = designs[d].name;
		container.appendChild(button);

		var checkbox = document.createElement("input");
		checkbox.setAttribute("type", "checkbox");
		checkbox.setAttribute("class", "checkbox");
		designs[d].checkbox = checkbox;
		container.appendChild(checkbox);
	}
}

var colors = new Map();
colors.set("111111", "BLACK");     //01
colors.set("000000", "BLACK");     //01
colors.set("ffffff", "WHITE");     //02
colors.set("ff0000", "RED");       //03
colors.set("00ff00", "GREEN");     //04
colors.set("0000ff", "BLUE");      //05
colors.set("00ffff", "CYAN");      //06
colors.set("ff00ff", "MAGENTA");   //07
colors.set("ffff00", "YELLOW");    //08
colors.set("ff8800", "ORANGE");    //09
colors.set("ff6464", "PINK");      //10
colors.set("bb0000", "DIM_RED");   //11
colors.set("000055", "DIM_BLUE");  //12
colors.set("003333", "DIM_CYAN");  //13
colors.set("bbbb00", "DIM_YELLOW");//14
colors.set("bb6600", "DIM_ORANGE");//15
colors.set("002222", "DARK_CYAN"); //16

var draw_count = 0;

function arrayToHTMLColor(arr) {
	return "#" + arr[0] + arr[1] + arr[2];
}

function draw() {
	ctx.fillStyle = "#000";
	ctx.fillRect(0, 0, 800, 600);
	
	var frame = draw_count % designs[current_design].pattern.length;
	for (i = 0; i < designs[current_design].pattern[0].length; i++) {
		for (j = 0; j < designs[current_design].pattern[0][0].length; j++) {
			ctx.fillStyle = arrayToHTMLColor(designs[current_design].pattern[frame][i][j]);
			ctx.beginPath();
			ctx.arc(25 + 50 * j, 25 + 50 * i, 10, 0, 2 * Math.PI, false);
			ctx.fill();
		}
	}
	draw_count++;
}

function setDesign(design) {
	current_design = design; 
	count = 0; 

	clearInterval(draw_interval); 
	draw_interval = setInterval(draw, designs[design].speed);
}

function sendToMascotCodeFile() {
	var target = 'mascot_code.html';

	var selected = "";
	for (var d in designs) {
		if (designs[d].checkbox.checked) {
			selected += d + ",";
		}
	}
	selected = selected.slice(0, -1);
	if (selected.length > 0) {	
		target += "?designs=[" + selected + "]";
	}
	
	window.open(target, "Mascot Code");
}
