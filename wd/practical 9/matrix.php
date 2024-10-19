<?php
function printMatrix($matrix) {
    foreach ($matrix as $row) {
        echo implode("\t", $row) . "\n";
    }
}

function transposeMatrix($matrix) {
    $transpose = [];
    for ($i = 0; $i < count($matrix[0]); $i++) {
        for ($j = 0; $j < count($matrix); $j++) {
            $transpose[$i][$j] = $matrix[$j][$i];
        }
    }
    return $transpose;
}

function addMatrices($matrixA, $matrixB) {
    $result = [];
    for ($i = 0; $i < count($matrixA); $i++) {
        for ($j = 0; $j < count($matrixA[0]); $j++) {
            $result[$i][$j] = $matrixA[$i][$j] + $matrixB[$i][$j];
        }
    }
    return $result;
}

function multiplyMatrices($matrixA, $matrixB) {
    $result = [];
    for ($i = 0; $i < count($matrixA); $i++) {
        for ($j = 0; $j < count($matrixB[0]); $j++) {
            $result[$i][$j] = 0;
            for ($k = 0; $k < count($matrixB); $k++) {
                $result[$i][$j] += $matrixA[$i][$k] * $matrixB[$k][$j];
            }
        }
    }
    return $result;
}

$matrixA = [
    [1, 2, 3],
    [4, 5, 6],
];

$matrixB = [
    [7, 8, 9],
    [10, 11, 12],
];

echo "Transpose of Matrix A:\n";
$transposeA = transposeMatrix($matrixA);
printMatrix($transposeA);

echo "\nAddition of Matrix A and B:\n";
$sum = addMatrices($matrixA, $matrixB);
printMatrix($sum);

echo "\nMultiplication of Matrix A and B:\n";
$product = multiplyMatrices($matrixA, $matrixB);
printMatrix($product);
?>
