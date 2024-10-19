<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Image Upload</title>
</head>
<body>
    <h2>Upload Image (GIF or JPEG)</h2>
    <form method="post" enctype="multipart/form-data">
        <label for="image">Select an image (GIF or JPEG):</label>
        <input type="file" id="image" name="image" accept=".gif, .jpeg, .jpg" required>
        <br><br>
        <input type="submit" value="Upload">
    </form>

    <?php
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $targetDir = "uploads/";
        $targetFile = $targetDir . basename($_FILES["image"]["name"]);
        $imageFileType = strtolower(pathinfo($targetFile, PATHINFO_EXTENSION));
        $uploadOk = 1;

        if ($_FILES["image"]["size"] > 200 * 1024) {
            echo "<p>Sorry, your file is too large. Maximum size is 200 kB.</p>";
            $uploadOk = 0;
        }

        if (!in_array($imageFileType, ["gif", "jpeg", "jpg"])) {
            echo "<p>Sorry, only GIF and JPEG files are allowed.</p>";
            $uploadOk = 0;
        }

        if ($uploadOk == 0) {
            echo "<p>Sorry, your file was not uploaded.</p>";
        } else {
            if (move_uploaded_file($_FILES["image"]["tmp_name"], $targetFile)) {
                echo "<p>The file " . htmlspecialchars(basename($_FILES["image"]["name"])) . " has been uploaded.</p>";
            } else {
                echo "<p>Sorry, there was an error uploading your file.</p>";
            }
        }
    }
    ?>
</body>
</html>
