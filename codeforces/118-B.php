<?php

// https://codeforces.com/problemset/problem/118/B

/*
 Example: (input=2)

    0
  0 1 0
0 1 2 1 0
  0 1 0
    0
*/

/*
 Example: (input=3)

      0
    0 1 0
  0 1 2 1 0
0 1 2 3 2 1 0
  0 1 2 1 0
    0 1 0
      0
*/

function getRowData(int $number): array
{
    $numberOfColumns = (($number * 2) + 1);
    $rowData = [];
    $clonedNumber = $number - 1;

    for ($i = 0; $i < $numberOfColumns; $i++) {
        if ($i <= $number) {
            array_push($rowData, $i);
        } else {
            array_push($rowData, $clonedNumber);
            $clonedNumber--;
        }
    }

    return $rowData;
}

function getRowDataAccordingToRowPosition(int $number, int $rowPosition): array
{
    if ($rowPosition <= $number) {
        return getRowData($rowPosition);
    }

    return getRowData((($number * 2)) - $rowPosition);
}

function getNumberOfNeededSpaces(int $number, int $rowPosition): int
{
    if ($rowPosition === $number) {
        return 0;
    }

    if ($rowPosition < $number) {
        return ($number - $rowPosition) * 2;
    }

    return ($rowPosition - $number) * 2;
}

function getUserInput(): int
{
    $handle = fopen('php://stdin', 'r');

    return (int) fgets($handle);
}

$number = getUserInput();
$numberOfRows = (($number * 2) + 1);
$matrix = [];

/*
 * Filling the matrix with row data
 * Ex: [[0], [0, 1, 0],..]
 */
for ($i = 0; $i < $numberOfRows; $i++) {
    array_push($matrix, getRowDataAccordingToRowPosition($number, $i));
}

/*
 * Printing the matrix data based on needed spaces
 */
foreach ($matrix as $rowPosition => $rowData) {
    echo str_repeat(' ', getNumberOfNeededSpaces($number, $rowPosition));
    echo implode(' ', $rowData);
    echo "\n";
}
