// Function to shuffle an array
function shuffleArray(array) {
  for (let i = array.length - 1; i > 0; i--) {
    const j = Math.floor(Math.random() * (i + 1));
    [array[i], array[j]] = [array[j], array[i]];
  }
}


$(document).ready(function () {
  // Initial tile data
  var tileData = {
    "pieces": [
      {"letter":"A", "value":1, "amount":9, "image": "Scrabble_Tile_A.jpg"},
      {"letter":"B", "value":3, "amount":2, "image": "Scrabble_Tile_B.jpg"},
      {"letter":"C", "value":3, "amount":2, "image": "Scrabble_Tile_C.jpg"},
      {"letter":"D", "value":2, "amount":4, "image": "Scrabble_Tile_D.jpg"},
      {"letter":"E", "value":1, "amount":12, "image": "Scrabble_Tile_E.jpg"},
      {"letter":"F", "value":4, "amount":2, "image": "Scrabble_Tile_F.jpg"},
      {"letter":"G", "value":2, "amount":3, "image": "Scrabble_Tile_G.jpg"},
      {"letter":"H", "value":4, "amount":2, "image": "Scrabble_Tile_H.jpg"},
      {"letter":"I", "value":1, "amount":9, "image": "Scrabble_Tile_I.jpg"},
      {"letter":"J", "value":8, "amount":1, "image": "Scrabble_Tile_J.jpg"},
      {"letter":"K", "value":5, "amount":1, "image": "Scrabble_Tile_K.jpg"},
      {"letter":"L", "value":1, "amount":4, "image": "Scrabble_Tile_L.jpg"},
      {"letter":"M", "value":3, "amount":2, "image": "Scrabble_Tile_M.jpg"},
      {"letter":"N", "value":1, "amount":5, "image": "Scrabble_Tile_N.jpg"},
      {"letter":"O", "value":1, "amount":8, "image": "Scrabble_Tile_O.jpg"},
      {"letter":"P", "value":3, "amount":2, "image": "Scrabble_Tile_P.jpg"},
      {"letter":"Q", "value":10, "amount":1, "image": "Scrabble_Tile_Q.jpg"},
      {"letter":"R", "value":1, "amount":6, "image": "Scrabble_Tile_R.jpg"},
      {"letter":"S", "value":1, "amount":4, "image": "Scrabble_Tile_S.jpg"},
      {"letter":"T", "value":1, "amount":6, "image": "Scrabble_Tile_T.jpg"},
      {"letter":"U", "value":1, "amount":4, "image": "Scrabble_Tile_U.jpg"},
      {"letter":"V", "value":4, "amount":2,"image": "Scrabble_Tile_V.jpg"},
      {"letter":"W", "value":4, "amount":2, "image": "Scrabble_Tile_W.jpg"},
      {"letter":"X", "value":8, "amount":1, "image": "Scrabble_Tile_X.jpg"},
      {"letter":"Y", "value":4, "amount":2, "image": "Scrabble_Tile_Y.jpg"},
      {"letter":"Z", "value":10, "amount":1, "image": "Scrabble_Tile_Z.jpg"}
    ]
  };
  // var remainingCount = tileData.pieces.reduce((sum, piece) => sum + piece.amount, 0);

  // Clone the original data for resetting
  var originalTileData = $.extend(true, {}, tileData);

  // Function to update remaining tiles count and check if submit button should be disabled
  function updateRemainingTilesCount(remainingCount) {
    remainingCount = tileData.pieces.reduce((sum, piece) => sum + piece.amount, 0);
    $('#tiles-count').text(remainingCount);
    console.log("in updateRemainingTilesCount():", remainingCount);
    // Disable submit button if remaining tiles are 0
    $('#submitBtn').prop('disabled', remainingCount === 0);

    return remainingCount;
  }

  // Function to deal tiles
  function dealTiles() {

    remainingCount = updateRemainingTilesCount();
    
    // Clear existing tiles on rack and board
    $('#scrabble-tile-rack, scrabble-board, scrabble-tile').empty();

    $ ('#tiles-count').text(remainingCount);

    // Clone the original data for dealing
    tileData = $.extend(true, {}, originalTileData);

    // Shuffle the tiles
    shuffleArray(tileData.pieces);

    // Calculate the size of a spot on the gameboard
    var spotSize = $('#scrabble-board .scrabble-square').width();

    // Define a maximum width and height for the tiles
    var maxTileSize = 40; // Adjust as needed

    // Display 7 tiles on the rack with appropriate size
    for (let i = 0; i < 7; i++) {
      // Calculate the adjusted tile size
      var tileSize = Math.min(spotSize, maxTileSize);

      $('#scrabble-tile-rack').append(
        `<div class="scrabble-tile" data-letter="${tileData.pieces[i].letter}" data-value="${tileData.pieces[i].value}" data-amount="${tileData.pieces[i].amount}">
          <img src="imgs/Scrabble_Tiles/${tileData.pieces[i].image}" alt="${tileData.pieces[i].letter}" style="width: ${maxTileSize}px; height: ${maxTileSize}px;">
        </div>`
      );

      tileData.pieces[i].amount = tileData.pieces[i].amount - 1;
      updateRemainingTilesCount();
    }

    
    console.log("In dealTiles():");

    // Update remaining tiles count
    // updateRemainingTilesCount();
  

    // Calculate the size of a spot on the gameboard
  var spotSize = $('#scrabble-board .scrabble-square').width();

 // Function to store the last dropped position
 function setLastDroppedPosition(tile, position) {
  tile.data('lastDroppedPosition', position);
}

// Function to get the last dropped position
function getLastDroppedPosition(tile) {
  return tile.data('lastDroppedPosition');
}

// Function to get the original position
function getOriginalPosition(tile) {
  return tile.data('originalPosition');
}

// Function to set the original position
function setOriginalPosition(tile, position) {
  tile.data('originalPosition', position);
}

// Make tiles draggable with snapping
$('.scrabble-tile').draggable({
  revert: function (dropped) {
    var originalPosition = getOriginalPosition($(this));
    var lastDroppedPosition = getLastDroppedPosition($(this));

    if (!dropped) {
      // If not dropped, return to the original position
      return true;
    }

    // If dropped, check if it was on the board or tile rack
    if ($(this).closest('#scrabble-board').length) {
      // If dropped on the board, return to the last dropped position on the board
      return !lastDroppedPosition;
    } else {
      // If dropped on the tile rack, return to the original position on the rack
      return !originalPosition;
    }
  },
  snap: '.scrabble-square, .scrabble-tile',
  stack: '.scrabble-tile',
  snapMode: 'inner',
  snapTolerance: 20,
  start: function (event, ui) {
    // Store the original position
    setOriginalPosition($(this), ui.offset);
  },
  stop: function (event, ui) {
    // Store the last dropped position
    setLastDroppedPosition($(this), ui.offset);
  },
});


  // Make squares on the board and tile rack droppable with snapping
  $('.scrabble-square.drop-target').droppable({
    accept: '.scrabble-tile',
    drop: function (event, ui) {
      var droppedTile = ui.helper;
      var letter = droppedTile.data('letter');
      var amount = droppedTile.data('amount');

      // Check if the drop target is the Scrabble board or tile rack
      if ($(this).is('.scrabble-square.drop-target')) {
        // Calculate the position within the board
        var position = ui.helper.offset();
        var boardPosition = $(this).offset();

        var leftOffset = position.left - boardPosition.left;
        var topOffset = position.top - boardPosition.top;

        // Snap to the closest spot on the board
        var snappedLeft = Math.round(leftOffset / spotSize) * spotSize;
        var snappedTop = Math.round(topOffset / spotSize) * spotSize;

        // Set position of the dropped tile within the board
        droppedTile.appendTo(this).css({ top: snappedTop, left: snappedLeft });
      } else if ($(this).is('#scrabble-tile-rack')) {
        // If dropped on the tile rack, simply append the tile
        droppedTile.appendTo(this);
      } else {
        // Check if the spot is empty and not already containing a tile
        if ($(this).is(':empty') && !$(this).children('.scrabble-tile').length) {
          // Update amount in tileData
          tileData.pieces.find(tile => tile.letter === letter).amount = amount - 1;

          // Update remaining tiles count
          // updateRemainingTilesCount();

          // Move the tile to the empty spot
          droppedTile.appendTo(this);
        } else {
          // Return the tile to its original spot
          droppedTile.draggable('option', 'revert', true);
        }
      }
    },
  });
  }

  // Initialize the game
  dealTiles();

  // Deal tiles button click event
  $('#dealTilesButton').on('click', function () {
    $('#scrabble-tile-rack, scrabble-board, scrabble-tile').empty();
    dealTiles();
  });

  // // Clear board button click event
  // $('#clearBoardButton').on('click', function () {
  //   $('#scrabble-board').empty();
  // });
});
