<?php

// https://codeforces.com/problemset/problem/71/A

$wordsArray = getUserInput();

foreach ($wordsArray as $word) {
    $wordLength = strlen($word);

    if (10 < $wordLength) {
        echo sprintf('%s%s%s', $word[0], $wordLength-3, $word[$wordLength-2]);
        echo "\n";
    } else {
        echo $word;
    }
}

function getUserInput()
{
    $handle = fopen("php://stdin","r");

    $numberOfWords = fgets($handle);
    $wordsArray = [];

    for ($i=0;$i<$numberOfWords;$i++) {
        array_push($wordsArray, fgets($handle));
    }

    return $wordsArray;
}