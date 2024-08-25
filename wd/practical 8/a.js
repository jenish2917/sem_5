function getBrowserDetails(){
    return{
    "User Agent": navigator.userAgent,
    "Platform": navigator.platform,
    "Language": navigator.language,
    "Online Status": navigator.onLine ?  "Online" : "Offline",
    "Cookies Enabled": navigator.cookieEnabled,
    "Screen Width" : screen.width + " px",
    "Screen Height":  screen.height + " px",
    "Windpw Width" :  window.innerWidth + " px",
    "Window Height" :   window.innerHeight + " px",
    "Color  Depth": screen.colorDepth + " bits",
    "Timezone" :  Intl.DateTimeFormat().resolvedOptions().timeZone
    };   
}

function displayBrowserDetails(){
    const details =  getBrowserDetails();
    const tableBody = document.getElementById("browser-details");

    for ( const [key, value] of  Object.entries(details)) {
        const row = document.createElement("tr");

        const cellkey = document.createElement("td");
        cellkey.textContent = key;
        row.appendChild(cellkey);

        const cellValue  = document.createElement("td");
        cellValue.textContent = value;
        row.appendChild(cellValue);

        tableBody.appendChild(row);
    }
}

displayBrowserDetails();
