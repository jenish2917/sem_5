<?php
session_start();
if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST["name"])) {
    $_SESSION["name"] = htmlspecialchars($_POST["name"]);
    $_SESSION["start_time"] = time();
} elseif (!isset($_SESSION["name"])) {
    header("Location: index.php");
    exit();
}

$name = $_SESSION["name"];
$start_time = date("Y-m-d H:i:s", $_SESSION["start_time"]);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Hello Page</title>
</head>
<body>
    <h2>Hello, <?php echo $name; ?>!</h2>
    <div style="position: absolute; top: 10px; right: 10px;">
        <p>Start Time: <?php echo $start_time; ?></p>
    </div>
    <form method="post" action="logout.php">
        <input type="submit" value="Logout">
    </form>
</body>
</html>
