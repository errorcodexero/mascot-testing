function parseCheckedDesigns(){
	var checked_designs = []
	var parameters = location.search.substring(location.search.lastIndexOf("[")+1,location.search.lastIndexOf("]")).split(",");
	for(var i = 0; i < parameters.length; i++){
		if(parameters[i] == '') continue;
		console.log(parameters[i]);
		for(var j = 0; j < designs.length; j++){
			if(designs[j].name == parameters[i]){
				checked_designs.push(new Design(designs[j].name,designs[j].speed,designs[j].pattern,true));
			}
		}
	}
	return checked_designs;
}

function isNotLastChecked(start,checked_designs){
	for(var i = start + 1; i < checked_designs.length; i++){
		if(checked_designs[i].checked){
			return true;
		}
	}
	return false;
}

function generateCCode() {
	var display = "";
	
	
	var checked_designs = parseCheckedDesigns();

	if(checked_designs.length == 0){
		display = "No designs selected";
	} else {	
		display += "#ifndef COLORS_H<br/>\
		#define COLORS_H <br/>\
		<br/>\
		#define ARDUINO_SAMD_ZERO //Define this for FastLED to work with Arduino M0 <br/>\
		#include \"FastLED.h\" <br/>\
		<br/>\
		#define COLOR_ORDER GRB <br/>\
		#define LED_CONTROLLER WS2812B <br/>\
		<br/>\
		static const uint8_t NUMBER_OF_LEDS = 192; <br/>\
		static const uint8_t BRIGHTNESS = 255 * 0.3; <br/>\
		static const uint8_t LED_STRIP_DATA_PIN = 3; <br/>\
		static const uint8_t NUMBER_OF_DESIGNS = " + count + "; <br/>\
		<br/>\
		enum Color_index{ <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;BLACK = 0, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;WHITE = 1, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;RED = 2, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;GREEN = 3, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;BLUE = 4, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;CYAN = 5, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;MAGENTA = 6, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;YELLOW = 7, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;ORANGE = 8, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;PINK = 9, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DIM_RED = 10, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DIM_BLUE = 11, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DIM_CYAN = 12, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DIM_YELLOW = 13, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DIM_ORANGE = 14, <br/>\
		&nbsp;&nbsp;&nbsp;&nbsp;DARK_CYAN = 15 <br/>\
		}; <br/>\
		<br/>\
		CRGB index_to_color(const uint8_t); <br/>\
		<br/>";
		
		{
			display += "constexpr PROGMEM uint16_t DESIGNS[NUMBER_OF_DESIGNS][3] = {//first is index of start of pattern, second is index of end of pattern, and the third is frame duration (ms) <br/>";
			
			var frame_number = 0;
			for(var s = 0; s < checked_designs.length; s++){
				if(checked_designs[s].checked){
					screen = checked_designs[s].pattern
					display += "&nbsp;&nbsp;&nbsp;&nbsp;{";
					for (a = 0; a < screen.length; a++) {
						if (a == 0) display += frame_number + ", ";
						if (a == screen.length - 1) display += frame_number + ", " ;
						frame_number++;
					}
					display += checked_designs[s].speed;
					display += "}";
					
					if(isNotLastChecked(s,checked_designs)){
						display += ",";
					}
					display += "  //" + checked_designs[s].name + " " + s + "<br/>";
				}
			}
			display += "};<br/>";
		}
		display += "<br/>static const uint16_t TOTAL_FRAME_COUNT = DESIGNS[NUMBER_OF_DESIGNS - 1][1] + 1;<br/><br/>";
		var undefined_color = false;
		{
			display += "constexpr PROGMEM uint8_t FRAMES[TOTAL_FRAME_COUNT][NUMBER_OF_LEDS] = {<br/>";
			var frame_number = 0;
			for (s = 0; s < checked_designs.length; s++) {
				if(checked_designs[s].checked){
					screen = checked_designs[s].pattern;
					for (a = 0; a < screen.length; a++) {
						display += "&nbsp;&nbsp;&nbsp;&nbsp;{"
						if (a == 0) display += "//First frame of "+checked_designs[s].name+" ("+frame_number+")";
						display += "<br/>";
						for (i = 0; i < screen[a].length; i++) {
							display += "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;";
							for (j = 0; j < screen[a][i].length; j++) {
								display += "Color_index::"+colors.get(screen[a][i][j][0]+screen[a][i][j][1]+screen[a][i][j][2]);
								if(colors.get(screen[a][i][j][0]+screen[a][i][j][1]+screen[a][i][j][2]) == undefined) undefined_color = true;
								if ((i + 1) < screen[a].length || (j + 1) < screen[a][i].length) display += ", ";
							}
							display += "<br/>";
						}
						display += "&nbsp;&nbsp;&nbsp;&nbsp;}"
						if (isNotLastChecked(s,checked_designs) || (a + 1 ) < screen.length){
							console.log("AHH");
							display += ",";
						}
						if (a == screen.length - 1) display += "//Last frame of "+checked_designs[s].name+" ("+frame_number+")";
						display += "<br/>";
						frame_number++;
					}
				}
			}
			display += "};<br/>";
		}
		
		display += "<br/>#endif";
		
	}
	
	document.getElementById("display").innerHTML = display;
	
	if(undefined_color) console.error("Error: undefined colors");
	
	//document.querySelector("#display").select();
	//document.execCommand("Copy");
}