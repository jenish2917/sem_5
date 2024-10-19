<?php
if (isset($_COOKIE["visit_count"])) {
    $visit_count = $_COOKIE["visit_count"] + 1;
} else {
    $visit_count = 1;
}

setcookie("visit_count", $visit_count, time() + 3600, "/");
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Visitor Counter</title>
</head>
<body>
    <h2>Visitor Counter</h2>
    <p>You have visited this page <?php echo $visit_count; ?> time(s).</p>
</body>
</html>
