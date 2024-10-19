<?php
session_start();
if (isset($_SESSION["start_time"])) {
    $duration = time() - $_SESSION["start_time"];
    $duration_minutes = floor($duration / 60);
    $duration_seconds = $duration % 60;
} else {
    header("Location: index.php");
    exit();
}

session_unset();
session_destroy();
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Logout Page</title>
</head>
<body>
    <h2>Thank You!</h2>
    <p>Your session lasted <?php echo $duration_minutes . " minutes and " . $duration_seconds . " seconds."; ?></p>
</body>
</html>
