<?php

if(isset($_POST['encrypt'])){
    $simple_string = $_POST['text'];
    echo "Original Data: " . $simple_string . "<br>";
    $ciphering = "AES-128-CTR"; // it store the cipher method
    $option = 0; // it hold the bitwise disjunction of the flags
    $encryption_iv = "1234567890123456"; // it hold the initialization vector which a not null
    $encryption_key = "sanghuonglinh"; // set the password
    $encryption = openssl_encrypt($simple_string, $ciphering, $encryption_key, $option, $encryption_iv);

    echo "Encrypted Data: " .$encryption . "<br>";


}
if(isset($_POST['dencrypt'])){
    $text = $_POST['text'];

    $ciphering = "AES-128-CTR"; // it store the cipher method
    $option = 0; // it hold the bitwise disjunction of the flags
    $decryption_iv = "1234567890123456"; // it hold the initialization vector which a not null
    $decryption_key = "sanghuonglinh"; // set the password
    $decryption = openssl_decrypt($text, $ciphering, $decryption_key, $option, $decryption_iv);

    echo "Decrypted Data: " .$decryption . "<br>";

}