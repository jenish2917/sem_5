<?php
if ($_SERVER["REQUEST_METHOD"] == "POST" && !empty($_POST["name"])) {
    $name = htmlspecialchars($_POST["name"]);
    setcookie("username", $name, time() + 3600, "/");
    $message = "Cookie has been set for $name.";
} else {
    $name = isset($_COOKIE["username"]) ? htmlspecialchars($_COOKIE["username"]) : null;
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Cookie Demo</title>
</head>
<body>
    <h2>Cookie Demo</h2>
    <form method="post" action="">
        <label for="name">Enter your name:</label>
        <input type="text" id="name" name="name" required>
        <input type="submit" value="Set Cookie">
    </form>

    <?php if (isset($message)): ?>
        <p><?php echo $message; ?></p>
    <?php endif; ?>

    <?php if ($name): ?>
        <h3>Welcome back, <?php echo $name; ?>!</h3>
    <?php else: ?>
        <p>No cookie found. Please enter your name.</p>
    <?php endif; ?>
</body>
</html>
