<?php

$handle = fopen('php://stdin', 'r');

$numberOfTestCases = fgets($handle);
$arrayElemetsArray = [];

for ($x = 0; $x < $numberOfTestCases; $x++) {
    $numberOfElementsInAnArray = fgets($handle);
    array_push($arrayElemetsArray, explode(' ', fgets($handle)));
}

foreach ($arrayElemetsArray as $arrayElemets) {
    $uniqueArray = array_unique($arrayElemets, SORT_NUMERIC);
    echo count($uniqueArray);
    echo "\n";
}
