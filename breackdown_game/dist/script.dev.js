"use strict";

var rulesBtn = document.getElementById('rules-btn');
var closeBtn = document.getElementById('close-btn');
var rules = document.getElementById('rules');
var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');
var score = 0;
var brickRowCount = 9;
var brickColumnCount = 5; // Create ball props

var ball = {
  x: canvas.width / 2,
  y: canvas.height / 2,
  size: 10,
  speed: 4,
  dx: 4,
  dy: -4
}; // create paddle props

var paddle = {
  x: canvas.width / 2 - 40,
  y: canvas.height - 20,
  w: 80,
  h: 10,
  speed: 8,
  dx: 0
}; // Draw ball on canvas

function drawBall() {
  ctx.beginPath();
  ctx.arc(ball.x, ball.y, ball.size, 0, Math.PI * 2);
  ctx.fillStyle = '#0095dd';
  ctx.fill();
  ctx.closePath();
} // Draw paddle on canvas


function drawPaddle() {
  ctx.beginPath();
  ctx.rect(paddle.x, paddle.y, paddle.w, paddle.h);
  ctx.fillStyle = '#0095dd';
  ctx.fill();
  ctx.closePath();
} // Draw everything


function draw() {
  drawBall();
  drawPaddle();
  drawScore();
} // Draw Score oon canvas


function drawScore() {
  ctx.font = '20px Arial';
  ctx.fillText("Score: ".concat(score), canvas.width - 100, 30);
}

draw(); // Rules and close event handlers

rulesBtn.addEventListener('click', function () {
  return rules.classList.add('show');
});
closeBtn.addEventListener('click', function () {
  return rules.classList.remove('show');
});