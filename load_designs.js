var colors = new Map();
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

function arrayToHTMLColor(arr) {
	return "#" + arr.join("");
}

var n_files = 0;

var designs = {};

var onCategoryCreation = function(category) {}
function Category(name, color, border_color, contents) {
	this.name = name;
	this.color = color;
	this.border_color = border_color;
	this.contents = contents;	

	n_files += contents.length;

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

	onCategoryCreation(this);
}

function setupCategories() {
	var files = {
		dial_0: new Category("Switch Position 0", "#AFF", "#3FF", [
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
		dial_1: new Category("Switch Position 1", "#FAF", "#F3F", [
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
		dial_2: new Category("Switch Position 2", "#FFA", "#FF3", [
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
			"blank",
			"box_flame",
			"flux",
			"game_of_life",
			"i_heart_robots",
			"nose",
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
}

var onDesignsLoaded = function() {}
var loaded = 0;
function addLoaded() {
	loaded++;
	if (loaded == n_files) {
		for (var d in designs) {
			if (designs[d].name == null) {
				name_parts = d.split("_");
				for (var i = 0; i < name_parts.length; i++) {
					name_parts[i] = name_parts[i].charAt(0).toUpperCase() + name_parts[i].slice(1);
				}
				designs[d].name = name_parts.join(" ");
			}
		}

		onDesignsLoaded();
	}
}
