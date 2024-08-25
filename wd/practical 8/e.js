function validateForm() {
    const userid  = document.getElementById('userid').value;
    const  password = document.getElementById('password').value;

    const mobilePattern = /^[0-9]{10}$/;
    const passwordPattern =  /^(?=.*[A-Z])(?=.*[!@#%&^&*])[A-Za-z\d!@#$%^&*]{8,}$/;

    const useridError = document.getElementById("useridError");
    const passwordError = document.getElementById("passwordError");

    let isValid = true;
    if(!mobilePattern.test(userid)){
        useridError.style.display = "block";
        isValid = false;
    }else{
        useridError.style.display = "none";
    }

    if(!passwordPattern.test(password)){
        passwordError.style.display = "block";
        isValid = false;
    }else{
        passwordError.style.display = "none";
    }
    return isValid;
}