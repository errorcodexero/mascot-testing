var canvas = document.getElementById("testing");
var ctx = (canvas != null) ? canvas.getContext("2d") : null;

console.clear();

var current_design = "smile";

var DRAW_DELAY = 200;
var draw_interval;

function cleanNode(node) {
  for(var i = 0; i < node.childNodes.length; i++) {
    var child = node.childNodes[i];
    if (child.nodeType === 8 || (child.nodeType === 3 && !/\S/.test(child.nodeValue))) {
      node.removeChild(child);
      i--;
    } else if (child.nodeType === 1) {
      cleanNode(child);
    }
  }
}
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
		"smile",
		"neutral",
		"frown",
		"space",
		"fire",
		"team",
		"tron",
		"pacman",
		"first",
		"surprise"
	],
	[ //Switch position 1
		"slide",
		"pong",
		"alert",
		"star",
		"blue",
		"red",
		"matrix",
		"wheel",
		"tetris",
		"wave"
	],
	[ //Switch position 2
		"portal",
		"wink",
		"color_bars",
		"pokeball",
		"maze",
		"box_flame",
		"i_heart_robots",
		"woah",
		"bear_2046",
		"playoffs"
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

function exportSelections() {
	var to_export = "";

	to_export += "var selector = [\n";
	for (var i = 0; i < selector.length; i++) {
		to_export += "\t[ //Switch position " + i + "\n";
		for (var j = 0; j < selector[i].length; j++) {
			to_export += "\t\t" + selector[i][j];
			if (j < selector[i].length - 1) {
				to_export += ",";
			}
			to_export += "\n";
		}
		to_export += "\t]";
		if (i < selector.length - 1) {
			to_export += ",";
		}
		to_export += "\n";
	}
	to_export += "]";

	document.getElementById("import_export").value = to_export;
}

function importSelections() {
	var to_import = document.getElementById("import_export").value.split(/[\[\]]+/);
	for (var i = to_import.length - 1; i >= 0; i--) {
		var comment_pos = to_import[i].indexOf("//");
		if (comment_pos != -1) {
			to_import[i] = to_import[i].substring(to_import[i].indexOf("\n"));
		}
		to_import[i] = to_import[i].replace(/[\s]/g, "");
		if (to_import[i].length == 0 || to_import[i] == "," || to_import[i] == "varselector=") {
			to_import.splice(i, 1);
		}
	}
	for (var i = 0; i < selector.length; i++) {
		selector[i] = to_import[i].split(",");
		for (var j = 0; j < selector[i].length; j++) {
			document.getElementById("di_" + i + "_" + j).innerHTML = designs[selector[i][j]].name;
		}
	}
}
