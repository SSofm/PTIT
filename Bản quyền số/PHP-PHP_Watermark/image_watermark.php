<?php

$directory = "image";
$images = glob($directory . "/*.jpg");
$temp = 0;
foreach($images as $image)
{
    $filename = pathinfo("image/$image", PATHINFO_FILENAME);
//    $filename = pathinfo($_FILES['image']['name'], PATHINFO_FILENAME);
//    echo $filename . "<br>";

//    echo $image . "<br>";

// load image
    $imgS = imagecreatefromjpeg("$image"); // source image
    $imgW = imagecreatefrompng("logo.png"); // watermark image

// get image size

    list($width, $height, $type, $attr) = getimagesize($image);

// Displaying dimensions of the image
//    echo "Width of image : " . $width . "<br>";
//
//    echo "Height of image : " . $height . "<br>";




// apply watermark image
    $Xratio = $width/3;
    $Yratio = $height/3;
//    imagecopy(
//                    $imgS, $imgW, // copy wwatermark onto source image
//                    0, 0, // x and y position to place watermark (top, left conrner)
//                    0, 0, imagesx($imgW), imagesy($imgW) // copy entire watermark image
//                );
//    imagecopy(
//        $imgS, $imgW, // copy wwatermark onto source image
//        $Xratio, 0, // x and y position to place watermark (top, left conrner)
//        0, 0, imagesx($imgW), imagesy($imgW) // copy entire watermark image
//    );
//    imagecopy(
//        $imgS, $imgW, // copy wwatermark onto source image
//        0, $Xratio, // x and y position to place watermark (top, left conrner)
//        0, 0, imagesx($imgW), imagesy($imgW) // copy entire watermark image
//    );

//    $run1 = 0;
    $temp1 = 0;

    for ($i = 0; $i <= $width+$Xratio; $i+=$Xratio){

        $temp2 = 0;
        for($j = 0; $j <= $height+$Yratio; $j+=$Xratio){

            if($temp1%2==0 && $temp2%2==0){
                imagecopy(
                    $imgS, $imgW, // copy wwatermark onto source image
                    $j, $i, // x and y position to place watermark (top, left conrner)
                    0, 0, imagesx($imgW), imagesy($imgW) // copy entire watermark image
                );
            }
            $temp2++;
//            $temp1 = 0;
        }
        $temp1++;
    }

//imagecopy(
//    $imgS, $imgW, // copy wwatermark onto source image
//    75, 100, // x and y position to place watermark (top, left conrner)
//    0, 0, imagesx($imgW), imagesy($imgW) // copy entire watermark image
//);

// saev wantermarked image
//    imagejpeg($imgS, "Result/watermarked" . $temp++ . ".jpg", 60);
    imagejpeg($imgS, "Result_ver2/$filename" . ".jpg", 60);
}

echo "Done!";


