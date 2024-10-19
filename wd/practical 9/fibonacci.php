<?php
function fibonacci($n) {
    $num1 = 0;
    $num2 = 1;
    
    echo $num1 . ", " . $num2;
    
    for ($i = 1; $i < $n - 1; $i++) {
        $sum = $num1 + $num2;
        echo ", " . $sum;
        $num1 = $num2;
        $num2 = $sum;
    }
}

$n = 10;
fibonacci($n);
?>
