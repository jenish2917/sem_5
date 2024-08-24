function calculateFactorial(){
    const number = parseInt(document.getElementById("inputNumber").value,10);
    const resultElement = document.getElementById("result");

    if (isNaN(number) || number<0){
        resultElement.textContent = "Please Enter a Non-Negative Integer.";
        return;
    }

    const factorial = (n) => {
        if (n==0 || n==1){
            return 1;
        }
        return n*factorial(n-1);
    };
    
    const result = factorial(number);
    resultElement.textContent = `Factorial of ${number} is ${result}.`
}