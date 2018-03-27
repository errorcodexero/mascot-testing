var canvas = document.getElementById("design");
var ctx = canvas.getContext("2d");

console.clear();

const WIDTH = 16;
const HEIGHT = 12;

var mouseX, mouseY;
var click = false;

var picking = false;

var screen = [new Array()];

for (i = 0; i < HEIGHT; i++) {
	screen[0][i] = new Array();
	for (j = 0; j < WIDTH; j++) {
		screen[0][i][j] = ["11","11","11"];
	}
}

var f = 0;

var color = "#ff0000";

function updateColor() {
	var r  = document.getElementById("rSl").value;
	document.getElementById("rLabel").innerHTML = r;
	var g = document.getElementById("gSl").value;
	document.getElementById("gLabel").innerHTML = g;
	var b = document.getElementById("bSl").value;
	document.getElementById("bLabel").innerHTML = b;
	document.getElementById("custom").style.backgroundColor = "#"+parseInt(r).toString(parseInt(WIDTH))+parseInt(g).toString(parseInt(WIDTH))+parseInt(b).toString(parseInt(WIDTH));
}

function addFrame(){
	var newF = new Array();

	for (i = 0; i < HEIGHT; i++) {
		newF[i] = new Array();
		for (j = 0; j < WIDTH; j++) {
			newF[i][j] = ["11","11","11"];
		}
	}
	
	if (f == screen.length - 1) screen[f+1] = newF;
	else screen.splice(f+1, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
}

function cloneFrame(){
	var newF = new Array();

	for (i = 0; i < HEIGHT; i++) {
		newF[i] = new Array();
		for (j = 0; j < WIDTH; j++) {
			newF[i][j] = [screen[f][i][j][0], screen[f][i][j][1], screen[f][i][j][2]];
		}
	}
	
	if (f == screen.length - 1) screen[f+1] = newF;
	else screen.splice(f+1, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
}

function deleteFrame(){
	if (screen.length > 1) {
		screen.splice(f,1);
		if (f > screen.length - 1) {
			f = screen.length - 1; 
			document.getElementById("fSl").value = f+1;
		}
		document.getElementById("fSl").max = screen.length;
		document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
	}
}

function updateFrame() {
	f = document.getElementById("fSl").value-1;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
}

function nextFrame() {
	if (f < screen.length - 1) f++;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
	document.getElementById("fSl").value = f+1;
}

function lastFrame() {
	if (f > 0) f--;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f+1)+"/"+document.getElementById("fSl").max;
	document.getElementById("fSl").value = f+1;
}

function shiftFrameLeft(){
	var newF = new Array();

	for (i = 0; i < HEIGHT; i++) {
		newF[i] = new Array();
		for (j = 1; j < WIDTH; j++) {
			newF[i][j - 1] = [screen[f][i][j][0], screen[f][i][j][1], screen[f][i][j][2]];
		}
		newF[i][WIDTH - 1] =  ["11","11","11"];
	}
	
	if (f == screen.length - 1) screen[f] = newF;
	else screen.splice(f, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f + 1)+"/"+document.getElementById("fSl").max;
}

function shiftFrameRight(){
	var newF = new Array();

	for (i = 0; i < HEIGHT; i++) {
		newF[i] = new Array();
		for (j = 0; j < WIDTH - 1; j++) {
			newF[i][j + 1] = [screen[f][i][j][0], screen[f][i][j][1], screen[f][i][j][2]];
		}
		newF[i][0] =  ["11","11","11"];
	}
	
	if (f == screen.length - 1) screen[f] = newF;
	else screen.splice(f, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f + 1)+"/"+document.getElementById("fSl").max;
}

function shiftFrameUp(){
	var newF = new Array();

	for (i = 1; i < HEIGHT; i++) {
		newF[i - 1] = new Array();
		for (j = 0; j < WIDTH; j++) {
			newF[i - 1][j] = [screen[f][i][j][0], screen[f][i][j][1], screen[f][i][j][2]];
		}
		
	}
	newF[HEIGHT - 1] = new Array();
	for (j = 0; j < WIDTH; j++) {
		newF[HEIGHT - 1][j] =  ["11","11","11"];
	}
	
	if (f == screen.length - 1) screen[f] = newF;
	else screen.splice(f, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f + 1)+"/"+document.getElementById("fSl").max;
}

function shiftFrameDown(){
	var newF = new Array();

	newF[0] = new Array();
	for (j = 0; j < WIDTH; j++) {
		newF[0][j] =  ["11","11","11"];
	}
	
	for (i = 0; i < HEIGHT - 1; i++) {
		newF[i + 1] = new Array();
		for (j = 0; j < WIDTH; j++) {
			newF[i + 1][j] = [screen[f][i][j][0], screen[f][i][j][1], screen[f][i][j][2]];
		}
		
	}
	
	if (f == screen.length - 1) screen[f] = newF;
	else screen.splice(f, 0, newF);
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+(f + 1)+"/"+document.getElementById("fSl").max;
}


function output() {
	var display = "[";
	for (a = 0; a < screen.length; a++) {
		display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;[";
		for (i = 0; i < screen[0].length; i++) {
			display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[";
			for (j = 0; j < screen[0][0].length; j++) {
				display += '["'+screen[a][i][j][0]+'","'+screen[a][i][j][1]+'","'+screen[a][i][j][2]+'"]';
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

function input() {
	var input = prompt("Paste array");
	eval("screen = "+input+";");
	if (f > screen.length - 1) {
		f = screen.length - 1; 
		document.getElementById("fSl").value = f+1;
	}
	document.getElementById("fSl").max = screen.length;
	document.getElementById("fLabel").innerHTML = (f+1)+"/"+document.getElementById("fSl").max;
}

function outputNew() {
	var label = prompt("Name header file (First letter capitalized, underscores between words)");
	var delay = prompt("Input the delay between frames in ms");
	var display = '#ifndef '+label.toUpperCase()+'_H<br/>#define '+label.toUpperCase()+'_H<br/><br/>#include "design.h"<br/><br/>struct '+label+': public Design {<br/>&nbsp;&nbsp;&nbsp;&nbsp;void set_leds(CRGB leds[Lights_constants::NUMBER_OF_LEDS])const{'+'<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;switch(current_frame){';
	/*var template = new Array();
	for (i = 0; i < screen[0].length; i++) {
		template[i] = new Array();
		for (j = 0; j < screen[0][i].length; j++) {
			var first = screen[0][i][j];
			var same = true;
			for (a = 1; a < screen.length; a++) {
				if (screen[a][i][j] != first) {
					same = false;
					break;
				}
			}
			template[i][j] = same;
			if (same) {
				display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;"
			}
		}
	}*/
	for (a = 0; a < screen.length; a++) {
		display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;case "+a+":";
		for(i = 0; i < screen[a].length; i++) {
			for(j = 0; j < screen[a][i].length; j++) {
				if(!(screen[a][i][j][0] == "11" && screen[a][i][j][1] == "11" && screen[a][i][j][2] == "11")) {
					display += '<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;leds['+(i*WIDTH + j)+'] = CRGB{';
					if (screen[a][i][j][0] != "11") display += parseInt(screen[a][i][j][0], WIDTH)+',';
					else display += '0,';
					if (screen[a][i][j][1] != "11") display += parseInt(screen[a][i][j][1], WIDTH)+',';
					else display += '0,';
					if (screen[a][i][j][2] != "11") display += parseInt(screen[a][i][j][2], WIDTH)+'};';
					else display += '0};';
				}
				if (i == screen[a].length - 1 && j == screen[a][i].length - 1) display += "<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;return;";
			}
		}
	}
	display += '<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;default:<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Serial.println("NYI");<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;assert(0);<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}<br/>&nbsp;&nbsp;&nbsp;&nbsp;}<br/><br/>&nbsp;&nbsp;&nbsp;&nbsp;'+label+'():Design('+screen.length+','+delay+'){}<br/>};<br/><br/>#endif';
	document.getElementById("display").innerHTML = display;
}

var colors = new Map();
colors.set("111111", "BLACK");     //01
colors.set("ffffff", "WHITE");     //02
colors.set("ff1111", "RED");       //03
colors.set("11ff11", "GREEN");     //04
colors.set("1111ff", "BLUE");      //05
colors.set("11ffff", "CYAN");      //06
colors.set("ff11ff", "MAGENTA");   //07
colors.set("ffff11", "YELLOW");    //08
colors.set("ff8811", "ORANGE");    //09
colors.set("ff6464", "PINK");      //10
colors.set("bb1111", "DIM_RED");   //11
colors.set("111155", "DIM_BLUE");  //12
colors.set("113333", "DIM_CYAN");  //13
colors.set("bbbb11", "DIM_YELLOW");//14
colors.set("bb6611", "DIM_ORANGE");//15
colors.set("112222", "DARK_CYAN"); //16


function outputConst() {
	var display = "";
	for (a = 0; a < screen.length; a++) {
		display += "{<br/>";
		for (i = 0; i < screen[a].length; i++) {
			display += "&nbsp;&nbsp;&nbsp;&nbsp;";
			for (j = 0; j < screen[a][i].length; j++) {
				display += "Color_index::"+colors.get(screen[a][i][j][0]+screen[a][i][j][1]+screen[a][i][j][2]);
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
	
	for (i = 0; i < screen[0].length; i++) {
		for (j = 0; j < screen[0][0].length; j++) {
			ctx.fillStyle = "#"+screen[f][i][j][0]+screen[f][i][j][1]+screen[f][i][j][2];
			ctx.beginPath();
			ctx.arc(25 + 50 * j, 25 + 50 * i, 10, 0, 2 * Math.PI, false);
			ctx.fill();
		}
	}
	
	//document.getElementById("design").style.border = "5px solid "+color+";";
}

document.onmousemove = function(e) {
    e = window.event || e;

    rect = canvas.getBoundingClientRect();
    mouseX = Math.round((e.clientX - rect.left));
    mouseY = Math.round((e.clientY - rect.top));
    
    if (click && mouseX > 0 && mouseX < 800 && mouseY > 0 && mouseY < 600) {
    	var x  = Math.round((mouseX - 25) / 50);
    	var y  = Math.round((mouseY - 25) / 50);
    	if (color.startsWith("#")) {	
			screen[f][y][x][0] = color.substr(1,2);
			screen[f][y][x][1] = color.substr(3,2);
			screen[f][y][x][2] = color.substr(5,2);
    	}
    	else {
			screen[f][y][x][0] = parseInt(color.substr(4,color.indexOf(",")-4)).toString(WIDTH);
			screen[f][y][x][1] = parseInt(color.substr(color.indexOf(",")+1,color.lastIndexOf(",")-color.indexOf(","))).toString(WIDTH);
			screen[f][y][x][2] = parseInt(color.substr(color.lastIndexOf(",")+1,color.length-color.lastIndexOf(","))).toString(WIDTH);
    	}
    }
}

document.onmousedown = function(e) {
    e = window.event || e;
    if(mouseX > 0 && mouseX < 800 && mouseY > 0 && mouseY < 600) {
    	var x  = Math.round((mouseX - 25) / 50);
    	var y  = Math.round((mouseY - 25) / 50);
    	if (picking) {
    		color = "#"+screen[f][y][x][0]+screen[f][y][x][1]+screen[f][y][x][2];
    		picking = false;
    	}
    	else {
			if (color.startsWith("#")) {	
				screen[f][y][x][0] = color.substr(1,2);
				screen[f][y][x][1] = color.substr(3,2);
				screen[f][y][x][2] = color.substr(5,2);
			}
			else {
				screen[f][y][x][0] = parseInt(color.substr(4,color.indexOf(",")-4)).toString(WIDTH);
				screen[f][y][x][1] = parseInt(color.substr(color.indexOf(",")+1,color.lastIndexOf(",")-color.indexOf(","))).toString(WIDTH);
				screen[f][y][x][2] = parseInt(color.substr(color.lastIndexOf(",")+1,color.length-color.lastIndexOf(","))).toString(WIDTH);
    		}
    	}
    }
    click = true;
}

document.onmouseup = function(e) {
    e = window.event || e;
    
    click = false;
}
