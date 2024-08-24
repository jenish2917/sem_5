
function calculateAge() {
    let birthdateInput = document.getElementById('birthdateInput').value;

    if (!birthdateInput) {
        document.getElementById('result').innerText = "Please enter your birthdate.";
        return;
    }

    let birthdate = new Date(birthdateInput);
    let today = new Date();

    let age = today.getFullYear() - birthdate.getFullYear();
    let monthDifference = today.getMonth() - birthdate.getMonth();
    
    if (monthDifference < 0 || (monthDifference === 0 && today.getDate() < birthdate.getDate())) {
        age--;
    }

    document.getElementById('result').innerText = "You are " + age + " years old.";
}
