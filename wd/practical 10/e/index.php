<?php
session_start();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Input Name</title>
</head>
<body>
    <h2>Enter Your Name</h2>
    <form method="post" action="hello.php">
        <input type="text" name="name" required>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
