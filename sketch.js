 var table;
 var c;
 //var timer;
var quote=[];
// This script will connect to a PHP endpoint and load color information.
// The colors will be used to fill the background of the canvas.
var img;
var img2;
var img3;
let timer = 20.00;
var distance;
function setup(){
  var canvas = createCanvas(windowWidth, windowHeight);
  canvas.parent("sketch");
  frameRate(121);
  // c = color(0); // default is black.
   getData();
  //
  //   // createCanvas(720, 400);
   img = loadImage("1.png");
   // img2 = loadImage("2.png");
    img3 = loadImage("3.png");
  // get new data every 5 seconds.
  // timer = setInterval(getData, 5000);
}

function draw(){

  image(img, 0, 0, windowWidth, windowHeight);
  receiveData();
  //background("#F6CFBE");
  fill("#000000");
   for(var r=0; r<table.getRowCount(); r++){
      distance = table.getString(r, 0);
  
   }
   
      for(var r=400; r<table.getRowCount(); r++){
      quote[r] = table.getString(r, 1);
      

   }
   console.log(quote[2708]);
   if(distance < 50){
   background("#6C47f7")
     //image(img/*3*/, 0, 0, windowWidth, windowHeight);
     textSize(40);
     fill("#F6CFBE");
    
     text(quote[2854],windowWidth/2-500,windowHeight/2);
  }

}
// //
 function getData(){
   // connect to database output to get most recent data.
   table = loadTable("output.php", "csv", receiveData);
 }
// //
 function receiveData(){
   // get red/green/blue values and build a color variable from them.
   //for(var r=0; r<table.getRowCount(); r++){
   //   distance = table.getString(r, 0);
   //
   //  console.log(distance);
   //  // c = color(red, green, blue);
   //}
 }
//
function windowResized(){
  resizeCanvas(windowWidth, windowHeight);
}
