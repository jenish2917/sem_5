<?php
function factorial($n) {
    if ($n < 0) return "Not defined for negative numbers.";
    if ($n == 0 || $n == 1) return 1;
    $result = 1;
    for ($i = 2; $i <= $n; $i++) $result *= $i;
    return $result;
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $number = intval($_POST["number"]);
    $factorial_result = factorial($number);
    echo "The factorial of $number is: $factorial_result";
}
?>

<!DOCTYPE html>
<html>
<head>
    <title>Factorial Calculator</title>
</head>
<body>
    <h2>Factorial Calculator</h2>
    <form method="post">
        <label for="number">Enter a number:</label>
        <input type="number" id="number" name="number" required>
        <input type="submit" value="Calculate">
    </form>
</body>
</html>
