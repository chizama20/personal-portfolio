const puzzleContainer = document.getElementById('puzzle-container');
const size = 4;
let tiles = [];
let emptyTile = { x: 3, y: 3 };

function init() {
    for (let i = 0; i < size * size - 1; i++) {
        tiles.push(i + 1);
    }
    tiles.push(null); 
    render();
    shuffle();
}

function render() {
    puzzleContainer.innerHTML = '';
    tiles.forEach((tile, index) => {
        const tileElement = document.createElement('div');
        tileElement.classList.add('tile');
        if (tile === null) {
            tileElement.classList.add('empty');
        } else {
            tileElement.textContent = tile;
            tileElement.addEventListener('click', () => moveTile(index));
        }
        puzzleContainer.appendChild(tileElement);
    });
}

function shuffle() {
    for (let i = tiles.length - 1; i > 0; i--) {
        const j = Math.floor(Math.random() * (i + 1));
        [tiles[i], tiles[j]] = [tiles[j], tiles[i]];
    }

    const emptyIndex = tiles.indexOf(null);
    emptyTile = { x: emptyIndex % size, y: Math.floor(emptyIndex / size) };
    render();
}

function moveTile(index) {
    const x = index % size;
    const y = Math.floor(index / size);

    const dx = Math.abs(x - emptyTile.x);
    const dy = Math.abs(y - emptyTile.y);

    if (dx + dy === 1) {
        tiles[emptyTile.y * size + emptyTile.x] = tiles[y * size + x];
        tiles[y * size + x] = null;
        emptyTile = { x, y };

        render();
    }
}

init();
