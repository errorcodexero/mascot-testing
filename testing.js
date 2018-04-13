var canvas = document.getElementById("testing");
var ctx = (canvas != null) ? canvas.getContext("2d") : null;

console.clear();

var current_design = "smile";

var DRAW_DELAY = 200;
var draw_interval;

cleanNode(document.body);

onCategoryCreation = function(category) {
	category.element = document.createElement("div");
	category.element.setAttribute("class", "category");
	category.element.style.backgroundColor = category.color;
	category.element.style.borderColor = category.border_color;
	document.getElementById("modes").appendChild(category.element);

	var header = document.createElement("h4");
	header.innerHTML = category.name;
	category.element.appendChild(header);
}

setupCategories();

onDesignsLoaded = function() {
	setupDesigns();
	setupSelector();
	draw_interval = (ctx != null) ? setInterval(draw, DRAW_DELAY) : null;
}

function setupDesigns() {	
	for (var d in designs) {
		var container = document.createElement("div");
		container.setAttribute("class", "design_container");
		designs[d].category.element.appendChild(container);

		var button = document.createElement("div");
		button.setAttribute("class", "design_button");
		button.setAttribute("onclick", "setDesign(\"" + d + "\")");
		button.setAttribute("draggable", "true");
		button.setAttribute("ondragstart", "dragDesign(event, \"" + d + "\")");
		button.setAttribute("onmouseover", "mouseOverDesign(event, \"" + d + "\")");
		button.setAttribute("onmouseout", "mouseOutDesign(event, \"" + d + "\")");
		button.innerHTML = designs[d].name;
		container.appendChild(button);	
	}
}

var selector = [
	[ //Switch position 0
		"smile", //Design 0, selector 100 
		"neutral", //Design 1, selector 101 
		"frown", //Design 2, selector 102 
		"space", //Design 3, selector 103 
		"fire", //Design 4, selector 104 
		"team", //Design 5, selector 105 
		"tron", //Design 6, selector 106 
		"pacman", //Design 7, selector 107 
		"first", //Design 8, selector 108 
		"surprise" //Design 9, selector 109 
	],
	[ //Switch position 1
		"slide", //Design 10, selector 200 
		"pong", //Design 11, selector 201 
		"alert", //Design 12, selector 202 
		"star", //Design 13, selector 203 
		"blue", //Design 14, selector 204 
		"red", //Design 15, selector 205 
		"matrix", //Design 16, selector 206 
		"wheel", //Design 17, selector 207 
		"tetris", //Design 18, selector 208 
		"wave" //Design 19, selector 209 
	],
	[ //Switch position 2
		"portal", //Design 20, selector 300 
		"wink", //Design 21, selector 301 
		"color_bars", //Design 22, selector 302 
		"pokeball", //Design 23, selector 303 
		"maze", //Design 24, selector 304 
		"box_flame", //Design 25, selector 305 
		"i_heart_robots", //Design 26, selector 306 
		"woah", //Design 27, selector 307 
		"bear_2046", //Design 28, selector 308 
		"nose" //Design 29, selector 309 
	]
];

var SWITCH_POSITIONS = 3;
var DIAL_POSITIONS = 10;
function setupSelector() {
	var selections_container = document.getElementById("selections");
	for (var i = 0; i < SWITCH_POSITIONS; i++) {
		var switch_col = document.createElement("div");
		switch_col.setAttribute("class", "switch_col");
		selections_container.appendChild(switch_col);

		var switch_header = document.createElement("div");
		switch_header.setAttribute("class", "switch_head");
		switch_header.innerHTML = i;
		switch_col.appendChild(switch_header);

		for (var j = 0; j < DIAL_POSITIONS; j++) {
			var dial_container = document.createElement("div");
			dial_container.setAttribute("class", "dial_container");
			switch_col.appendChild(dial_container);

			var dial_label = document.createElement("div");
			dial_label.setAttribute("class", "dial_label");
			dial_label.innerHTML = j;
			dial_container.appendChild(dial_label);

			var dial_item = document.createElement("div");
			dial_item.setAttribute("class", "dial_item");
			dial_item.setAttribute("id", "di_" + i + "_" + j)
			dial_item.setAttribute("ondragover", "dragDesignOver(event)");
			dial_item.setAttribute("ondrop", "dropDesign(event, " + i + ", " + j + ")");
			dial_item.innerHTML = designs[selector[i][j]].name;
			dial_container.appendChild(dial_item);
		}
	}
}

var draw_count = 0;

function draw() {
	ctx.fillStyle = "#000";
	ctx.fillRect(0, 0, 800, 600);
	
	var frame = draw_count % designs[current_design].pattern.length;
	for (i = 0; i < designs[current_design].pattern[0].length; i++) {
		for (j = 0; j < designs[current_design].pattern[0][0].length; j++) {
			ctx.fillStyle = designs[current_design].pattern[frame][i][j];
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

function generateArduinoCode() {
	var target = 'mascot_code.html';
	
	var selected = "";
	for (var i = 0; i < selector.length; i++) {
		for (var j = 0; j < selector[i].length; j++) {
			selected += selector[i][j] + ",";
		}
	}
	selected = selected.slice(0, -1);
	if (selected.length > 0) {	
		target += "?designs=[" + selected + "]";
	}
	
	window.open(target, "Mascot Code");
}

function setSelectorBackgrounds(name, color) {
	for (var i = 0; i < selector.length; i++) {
		for (var j = 0; j < selector[i].length; j++) {
			if (selector[i][j] == name) {
				document.getElementById("di_" + i + "_" + j).style.backgroundColor = color;
			}
		}
	}
}

function mouseOverDesign(evt, name) {
	setSelectorBackgrounds(name, "#D00");
}

function mouseOutDesign(evt, name) {
	setSelectorBackgrounds(name, "#888");
}

function dragDesign(evt, name) {
	evt.dataTransfer.setData("design", name);
}

function dragDesignOver(evt) {
	evt.preventDefault();
}

function dropDesign(evt, switch_pos, dial_pos) {
	evt.preventDefault();
	var design = evt.dataTransfer.getData("design");
	evt.target.innerHTML = designs[design].name;
	selector[switch_pos][dial_pos] = design;
}

function clearSelections() {
	for (var i = 0; i < selector.length; i++) {
		for (var j = 0; j < selector[i].length; j++) {
			selector[i][j] = "blank";
			document.getElementById("di_" + i + "_" + j).innerHTML = designs.blank.name;
		}
	}
}

function exportSelections() {
	var to_export = "";

	to_export += "selector = [\n";
	for (var i = 0; i < selector.length; i++) {
		to_export += "\t[ //Switch position " + i + "\n";
		for (var j = 0; j < selector[i].length; j++) {
			to_export += "\t\t\"" + selector[i][j] + "\"";
			if (j < selector[i].length - 1) {
				to_export += ",";
			}
			to_export += " //Design " + (i * 10 + j) + ", selector " + ((i + 1) * 100 + j) + " \n";
		}
		to_export += "\t]";
		if (i < selector.length - 1) {
			to_export += ",";
		}
		to_export += "\n";
	}
	to_export += "];";

	document.getElementById("import_export").value = to_export;
}

function importSelections() {
	eval(document.getElementById("import_export").value);
	for (var i = 0; i < selector.length; i++) {
		for (var j = 0; j < selector[i].length; j++) {
			document.getElementById("di_" + i + "_" + j).innerHTML = designs[selector[i][j]].name;
		}
	}
}
