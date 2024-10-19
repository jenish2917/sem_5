<?php
$filename = "notes.txt"; 

if (file_exists($filename)) {
    $content = file_get_contents($filename);
    $lines = explode("\n", $content);
    $lineCount = count($lines);
    $wordCount = str_word_count($content);
    $charCount = strlen($content);

    echo "<h2>File Content:</h2>";
    echo "<pre>" . htmlspecialchars($content) . "</pre>";
    echo "<h3>Statistics:</h3>";
    echo "<p>Total Lines: $lineCount</p>";
    echo "<p>Total Words: $wordCount</p>";
    echo "<p>Total Characters: $charCount</p>";
} else {
    echo "<p>The file does not exist.</p>";
}
?>
