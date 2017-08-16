'use strict';

//Get Elements
var player = document.getElementById('bgvid');
var mp4Source = document.getElementById('mp4Source');
var song = document.getElementById('song');
var noise = document.getElementById('noise');

//Set Volume
song.volume = 0.8;
noise.volume = 0.5;

//Frame Rate; there isn't a getFrame() method
var frame = 1 / 24.075;

var left = 0,
    right = 1;

var Jim = 0,
    Kevin = 1,
    Oz = 2,
    Finch = 3;

//Create array of objects mirroring the struct style used in C++ version	
var clips = [clip('Kevin_1', 0, 32, right, Kevin), clip('Kevin_1r', 34, 65, left, Kevin), clip('Kevin_2', 66, 94, left, Kevin), clip('Kevin_2r', 96, 122, right, Kevin), clip('Jim_1', 124, 165.5, left, Jim), clip('Jim_1r', 168, 208.5, right, Jim), clip('Jim_2', 211, 240.5, right, Jim), clip('Jim_2r', 243, 271.5, left, Jim), clip('Oz_1', 274, 292, left, Oz), clip('Oz_1r', 294, 313, right, Oz), clip('Oz_2', 315, 347, left, Oz), clip('Oz_2r', 349, 381, right, Oz), clip('Finch_1', 383, 445, right, Finch), clip('Finch_1r', 447, 508, left, Finch), clip('Finch_2', 510, 555, right, Finch), clip('Finch_2r', 557, 600, left, Finch)];

var current = clips[0],
    change,
    pOrientation,
    pCharacter,
    pChange,
    loaded;

loadVideo();
//On an interval of time run the update function
setInterval(function () {
	update();
}, .01);

//The Meat
function update() {
	if (player.currentTime >= current.stop && loaded == true) {

		pOrientation = current.orientation;
		pCharacter = current.character;
		pChange = change;

		while (change === pChange || clips[change].character === pCharacter || clips[change].orientation === pOrientation) {
			//console.log(current);
			rando();
		}
		current = clips[change];
		//console.log(current.name);
		player.currentTime = current.start;
	}
}

//This isn't that necessary 
function randomInt(min, max) {
	return Math.floor(Math.random() * (max - min + 1) + min);
}

//This is somewhat like designing a struct
//creates an object with info to be used in switching clips
function clip(name, start, stop, orientation, character) {

	var obj = {
		name: name,
		start: start * frame,
		stop: stop * frame,
		orientation: orientation,
		character: character
	};

	return obj;
}

//Quick random number generator
function rando() {
	change = randomInt(0, 15);
}

//Potential solution for video loading issue
function loadVideo() {

	console.log('Downloading video...');
	var xhr = new XMLHttpRequest();
	xhr.open('GET', '/images/theBoys_pr.mp4', true);
	xhr.responseType = 'blob';
	xhr.onload = function (e) {
		if (this.status == 200) {
			console.log('got it');
			var myBlob = this.response;
			var vid = (window.URL ? URL : URL).createObjectURL(myBlob);
			// myBlob is now the blob that the object URL pointed to.
			console.log('Loading video into element');
			player.src = vid;
			// not needed if autoplay is set for the video element
			loaded = true;
			player.play();
		}
	};
	xhr.send();
}
//# sourceMappingURL=main.js.map
