const base_url =
  "https://cdn.jsdelivr.net/gh/fawazahmed0/currency-api@1/latest/currencies";
const btn = document.querySelector("form button");
const dropdowns = document.querySelectorAll(".dropdown select");
const fromCurr = document.querySelector(".from select");
const toCurr = document.querySelector(".to select");
const resultElement = document.querySelector(".result"); 

for (let select of dropdowns) {
  for (let currCode in countryList) {
    let newOption = document.createElement("option");
    newOption.innerText = currCode;
    newOption.value = currCode;
    if (select.name === "from" && currCode === "USD") {
      newOption.selected = "selected";
    } else if (select.name === "to" && currCode === "INR") {
      newOption.selected = "selected";
    }
    select.appendChild(newOption);
  }
  select.addEventListener("change", (evt) => {
    UpdateFlag(evt.target);
  });
}

const UpdateFlag = (element) => {
  let currCode = element.value;
  let countryCode = countryList[currCode];
  let newSrc = `https://flagsapi.com/${countryCode}/flat/64.png`;
  let img = element.parentElement.querySelector("img");
  img.src = newSrc;
};

btn.addEventListener("click", async (evt) => {
  evt.preventDefault();
  let amount = document.querySelector(".amount input");
  let amtVal = amount.value;
  if (amtVal === "" || amtVal < 1) {
    amtVal = 1;
    amount.value = "1";
  }

  const URL = `${base_url}/${fromCurr.value.toLowerCase()}/${toCurr.value.toLowerCase()}.json`;
  console.log("Fetching URL:", URL); 

  try {
    let response = await fetch(URL);
    if (!response.ok) {
      let errorText = await response.text();
      console.error("Error fetching the exchange rate:", errorText);
      throw new Error(`HTTP error! Status: ${response.status}`);
    }
    let data = await response.json();
    let result = data[toCurr.value.toLowerCase()] * amtVal;
    if (resultElement) {
      resultElement.innerText = result;
    } else {
      console.error("Result element is null");
    }
  } catch (error) {
    console.error("Error fetching the exchange rate:", error);
    if (resultElement) {
      resultElement.innerText ="Failed to fetch the exchange rate. Please try again later.";
    }
  }
});
