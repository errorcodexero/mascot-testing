var canvas = document.getElementById("testing");
var ctx = canvas.getContext("2d");

console.clear();

setInterval(draw, 10);

var screen = []

function draw() {
	ctx.fillStyle = "#111";
	ctx.fillRect(0, 0, 800, 600);
}