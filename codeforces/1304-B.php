<?php

$handle = fopen ("php://stdin","r");

$inputArray = [];

$inputArray = explode(' ', fgets($handle));

$numberOfStrings = $inputArray[0];
$lengthOfStrings = $inputArray[1];

$stringsArray = [];

for($x=0;$x<$numberOfStrings;$x++) {
    array_push($stringsArray, fgets($handle));
}

print_r($stringsArray);

function getLongestPalindorme(array $stringsArray)
{
    return true;
}

function isPalidrom(string $string): bool
{
    $stringLength = strlen($string);

    if(1 == $stringLength)
        return true;

    if($stringLength %2 == 0) {
        $arr = str_split($string, $stringLength/2);
        return $arr[0] == strrev($arr[1]);
    }

    $replacedString = substr_replace($string, '', $stringLength+1/2, 1);
    $arr = str_split($replacedString, $stringLength-1/2);
    return $arr[0] == strrev($arr[1]);
}

?>

