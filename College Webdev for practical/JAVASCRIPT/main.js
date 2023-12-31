const areavaluekilo = {
    "sqkm": 1,
    "sqm": 1000000,
    "ha": 100,
    "acre": 247.105,
    "sqmi": 0.386102,
    "sqyd": 1196000,
    "sqft": 10760000,
    "sqin": 1550000000

}

const convertButton = document.querySelector(".convert-btn");

convertButton.addEventListener('click', function convert() {
    const convertOption1 = document.getElementById('a1').value;
    console.log(convertOption1)
    const convertOption2 = document.getElementById('a2').value;
    console.log(convertOption1)
    const value = document.getElementById('value').value;

    let areaConverterPopupP = document.querySelector('.area-converter-popup p');
    let areaConverterPopupCont = document.querySelector('.area-converter-popup');

    areaConverterPopupP.style.display = 'flex';
    areaConverterPopupCont.style.display = 'flex';

    let convertedArea;
    let convertedAreaKM;
    for (keys in areavaluekilo) {
        if (keys == convertOption2) {
            if (convertOption1 == 'sqkm') {
                convertedArea = Number(value) * areavaluekilo[keys];
                areaConverterPopupP.innerHTML = convertedArea;
                break;
            }
            else {
                for (keys2 in areavaluekilo) {
                    if (keys2 == convertOption1) {
                        convertedAreaKM = Number(value) / areavaluekilo[keys2];
                        convertedArea = convertedAreaKM * areavaluekilo[convertOption2];

                        areaConverterPopupP.innerHTML = convertedArea;
                        break;
                    }
                }

            }
        }
    }
})

let areaConverterPopupBtn = document.querySelector('.area-converter-popup button');
areaConverterPopupBtn.addEventListener('click', function reConvert() {
    let areaConverterPopupCont = document.querySelector('.area-converter-popup');

    areaConverterPopupCont.style.display = "none";
})