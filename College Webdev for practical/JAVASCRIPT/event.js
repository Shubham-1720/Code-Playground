const createButton = document.querySelector('btn');

let tablepop = document.querySelector('.popup')



createButton.addEventListener('click', function create(){
    let valueTable = document.getElementById('value').value;
let table;
function create(){
    for (let index = 1; index < 11; index++) {
        table = valueTable * index;
        tablepop.innerHTML = table;
        
    }
}
});