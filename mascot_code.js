var display = "";
function generateCCode() {
	var open_index = location.search.lastIndexOf("["), close_index = location.search.lastIndexOf("]");

	if(open_index == -1 || close_index == -1){
		display = "No designs selected";
	} else {	
		var checked_designs = location.search.substring(open_index + 1, close_index).split(",");
		display +=
"#ifndef COLORS_H\n\
#define COLORS_H \n\
\n\
#define ARDUINO_SAMD_ZERO //Define this for FastLED to work with Arduino M0 \n\
#include \"FastLED.h\" \n\
\n\
#define COLOR_ORDER GRB \n\
#define LED_CONTROLLER WS2812B \n\
\n\
static const uint8_t NUMBER_OF_LEDS = 192; \n\
static const uint8_t BRIGHTNESS = 255 * 0.3; \n\
static const uint8_t LED_STRIP_DATA_PIN = 3; \n\
static const uint8_t NUMBER_OF_DESIGNS = " + checked_designs.length + "; \n\
\n\
enum Color_index{ \n\
    BLACK = 0, \n\
    WHITE = 1, \n\
    RED = 2, \n\
    GREEN = 3, \n\
    BLUE = 4, \n\
    CYAN = 5, \n\
    MAGENTA = 6, \n\
    YELLOW = 7, \n\
    ORANGE = 8, \n\
    PINK = 9, \n\
    DIM_RED = 10, \n\
    DIM_BLUE = 11, \n\
    DIM_CYAN = 12, \n\
    DIM_YELLOW = 13, \n\
    DIM_ORANGE = 14, \n\
    DARK_CYAN = 15 \n\
}; \n\
\n\
CRGB index_to_color(const uint8_t); \n\
\n";
		
		{
			display += "constexpr PROGMEM uint16_t DESIGNS[NUMBER_OF_DESIGNS][3] = {//first is index of start of pattern, second is index of end of pattern, and the third is frame duration (ms) \n";
			
			var frame_number = 0;
			for(var s = 0; s < checked_designs.length; s++){
				screen = designs[checked_designs[s]].pattern
				display += "    {";
				for (a = 0; a < screen.length; a++) {
					if (a == 0) display += frame_number + ", ";
					if (a == screen.length - 1) display += frame_number + ", " ;
					frame_number++;
				}
				display += designs[checked_designs[s]].speed;
				display += "}";
				
				if(s < checked_designs.length - 1){
					display += ",";
				}
				display += "  //" + designs[checked_designs[s]].name + " - Design " + s + ", selector " + ((Math.floor(s / 10) + 1) * 100 + s % 10) + " " + "\n";
			}
			display += "};\n";
		}
		display += "\nstatic const uint16_t TOTAL_FRAME_COUNT = DESIGNS[NUMBER_OF_DESIGNS - 1][1] + 1;\n\n";
		var undefined_color = false;
		{
			display += "constexpr PROGMEM uint8_t FRAMES[TOTAL_FRAME_COUNT][NUMBER_OF_LEDS] = {\n";
			var frame_number = 0;
			for (s = 0; s < checked_designs.length; s++) {
				screen = designs[checked_designs[s]].pattern;
				for (a = 0; a < screen.length; a++) {
					display += "    {"
					if (a == 0) display += "//First frame of "+designs[checked_designs[s]].name+" ("+frame_number+")";
					display += "\n";
					for (i = 0; i < screen[a].length; i++) {
						display += "        ";
						for (j = 0; j < screen[a][i].length; j++) {
							display += "Color_index::"+colors.get(screen[a][i][j][0]+screen[a][i][j][1]+screen[a][i][j][2]);
							if(colors.get(screen[a][i][j][0]+screen[a][i][j][1]+screen[a][i][j][2]) == undefined) undefined_color = true;
							if ((i + 1) < screen[a].length || (j + 1) < screen[a][i].length) display += ", ";
						}
						display += "\n";
					}
					display += "    }"
					if (s < checked_designs.length - 1 || (a + 1 ) < screen.length){
						display += ",";
					}
					if (a == screen.length - 1) display += "//Last frame of "+designs[checked_designs[s]].name+" ("+frame_number+")";
					display += "\n";
					frame_number++;
				}
			}
			display += "};\n";
		}
		
		display += "\n#endif";
		
	}
	
	document.getElementById("display").value = display;
	
	if(undefined_color) console.error("Error: undefined colors");
	
	//document.querySelector("#display").select();
	//document.execCommand("Copy");
}

setupCategories();
onDesignsLoaded = generateCCode;

function copyCode() {
	document.getElementById("display").select();
	document.execCommand("copy");
}

function downloadCode() {
	var link = document.createElement("a");
	link.setAttribute("href", "data:text/plain;charset=utf-8," + encodeURIComponent(display));
	link.setAttribute("download", "colors.h");
	link.style.display = "none";
	document.body.appendChild(link);

	link.click();
	
	document.body.removeChild(link);
}
