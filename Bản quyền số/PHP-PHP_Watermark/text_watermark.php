<?php

// load image
$img = imagecreatefromjpeg("cat.jpg");


$wmtxt = "Copyright.";
$wmfont = "C:\Windows\Fonts\Arial.ttf";

$wmsize = 98;
$wmcolor = imagecolorallocatealpha($img, 255, 0, 0, 75); // red
$posX = 150; // place at left side of image
$posY = 54; // place at top of image

imagettftext($img, $wmsize, 0, $posX, $posX, $wmcolor,  $wmfont, $wmtxt);

imagejpeg($img, "watermarked.jpg", 60);




echo "nguyen van sang"
?>