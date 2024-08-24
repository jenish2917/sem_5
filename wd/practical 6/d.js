function isPrime(num) {
    if (num <= 1) return false; 
        if (num === 2) return true;
            if (num % 2 === 0) return false; 
            
    for (let i = 3; i * i <= num; i += 2) {
        if (num % i === 0) return false;
    }

    return true;
}

function checkPrime() {
    let userInput = document.getElementById('numberInput').value;
    let number = parseInt(userInput, 10);

    if (isNaN(number)) {
        document.getElementById('result').textContent = "The input is not a valid integer.";
    } else if (number < 0) {
        document.getElementById('result').textContent = "Please enter a positive integer.";
    } else {
        // Check if the number is prime and display the result
        if (isPrime(number)) {
            document.getElementById('result').textContent = number + " is a prime number.";
        } else {
            document.getElementById('result').textContent = number + " is not a prime number.";
        }
    }
}