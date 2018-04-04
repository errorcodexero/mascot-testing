var canvas = document.getElementById("testing");
var ctx = (canvas != null) ? canvas.getContext("2d") : null;

console.clear();

var current_design = "smile";

var DRAW_DELAY = 200;
var draw_interval;

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
	draw_interval = (ctx != null) ? setInterval(draw, DRAW_DELAY) : null;
}

function setupDesigns() {	
	for (var d in designs) {
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
