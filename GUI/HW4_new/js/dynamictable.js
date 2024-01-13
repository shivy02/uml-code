/***************************************
* Author: Shivam Patel
* Email: Shivam_Patel3@student.uml.edu
* GitHub: shivy02
***************************************/

//capture values from the input form
function captureValues() {
  //capture the values needed
  let input1 = parseInt(document.getElementById("row-one").value);
  let input2 = parseInt(document.getElementById("row-two").value);
  let input3 = parseInt(document.getElementById("col-one").value);
  let input4 = parseInt(document.getElementById("col-two").value);
  let table = document.getElementsByClassName("table");

  //store the captured values in an object to pass by reference
  var values = {
    x1: input1,
    x2: input2,
    y1: input3,
    y2: input4,
    t: table,
  };

  //check order of the values from the form and swap
  checkOrder(values);

  //return values obj
  return values;
}
//check the order of the values
function checkOrder(values) {
  //swap values if needed
  if (values.x1 > values.x2) {
    var temp = values.x1;
    var temp2 = values.x2;
    values.x1 = temp2;
    values.x2 = temp;
  }

  if (values.y1 > values.y2) {
    var temp = values.y1;
    var temp2 = values.y2;
    values.y1 = temp2;
    values.y2 = temp;
  }
}

//generate the table based on the values by appeding to the tableHTMl string
function generateTable() {

  let values = captureValues(); //get values object

  //first cell
  var tableHTML = "<thead> <tr> <th> </th>";
 
  //initialize horizontal axis
  for (var i = values.x1; i <= values.x2; i++) {
    tableHTML += "<th>" + i + "</th>";
  }
  //end of first row
  tableHTML += "</tr> </thead> <tbody> ";

  //initialize vertical range and row values
  for (var j = values.y1; j <= values.y2; j++) {
    tableHTML += '<tr> <th scope="row">' + j + "</td>";
    for (var i = values.x1; i <= values.x2; i++) {
      tableHTML += "<td>" + j * i + "</td>";
    }
    tableHTML += "</tr>";
  }
  tableHTML += "<tbody";
  values.t[0].innerHTML = tableHTML; //need to index table due to getElementByClass
}

//make the sliders
function initSliders() {

  // Initialize sliders
  $("#slider-row-one").slider({
    min: -50,
    max: 50,
    slide: function (event, ui) {
        $("#row-one").val(ui.value);
        generateTable(); // Update table when slider is changed
    }
  });

  $("#slider-row-two").slider({
    min: -50,
    max: 50,
    slide: function (event, ui) {
        $("#row-two").val(ui.value);
        generateTable(); // Update table when slider is changed
    }
  });

  $("#slider-col-one").slider({
    min: -50,
    max: 50,
    slide: function (event, ui) {
        $("#col-one").val(ui.value);
        generateTable(); // Update table when slider is changed
    }
  });

  $("#slider-col-two").slider({
    min: -50,
    max: 50,
    slide: function (event, ui) {
        $("#col-two").val(ui.value);
        generateTable(); // Update table when slider is changed
    }
  });
}

function addTableTab(values) {
  var label ="Tab: " + alues.x1 + "-" + values.x2 +  ", " + values.y1 + "-" + values.y2;

  var tabTemplate = "<li><a href='#{href}'>#{label}</a><span class='ui-icon ui-icon-close' role='presentation'>Remove Tab</span></li>";
  var id = "tab-" +values.x1 + "-" +values.x2 + "_" + values.y1 + "-" + values.y2;

  // Check if the tab already exists
  var existingTab = $("#" + id);

  if (existingTab.length > 0) {-
    // If it exists, activate the tab
    $("#tabs").tabs("option", "active", existingTab.index());
  } else {
    // If it doesn't exist, add a new tab
    $("#tabs ul").append(
      tabTemplate
        .replace(/#\{href\}/g, "#" + id)
        .replace(/#\{label\}/g, label)
    );
    $("#tabs").append(
      "<div id='" +
        id +
        "' class='table-container'><div class='table-responsive'><table class='table table-striped'>" +
        $(".table-responsive table").html() +
        "</table></div></div>"
    );
    $("#tabs").tabs("refresh");
    $("#tabs").tabs("option", "active", -1); // Activate the last added tab

    // Enable tab deletion on close button click
    $("#tabs").delegate(
      "span.ui-icon-close",
      "click",
      function () {
        var panelId = $(this).closest("li").remove().attr("aria-controls");
        $("#" + panelId).remove();
        $("#tabs").tabs("refresh");
      }
    );
  }
}
//generate the table when the document is fully validated using its id
$(document).ready(function () {
    // Initialize form validation

    initSliders();

    $("#inputForm").validate({
        rules: {
            num1: { required: true, number: true, float: true, range: [-50, 50] },
            num2: { required: true, number: true, float: true, range: [-50, 50] },
            num3: { required: true, number: true, float: true, range: [-50, 50] },
            num4: { required: true, number: true, float: true, range: [-50, 50] },
        },
        messages: {
            num1: {
                required: "Both bounds are required for the horizontal axis.",
                number: "Please enter a valid integer.",
                range: "Please enter an integer between -50 and 50.",
                float: "Floats are not supported, please enter integers only."
            },
            num2: {
                required: "Both bounds are required for the horizontal axis.",
                number: "Please enter a valid integer.",
                range: "Please enter an integer between -50 and 50.",
                float: "Floats are not supported, please enter integers only."
            },
            num3: {
                required: "Both bounds are required for the vertical axis.",
                number: "Please enter a valid integer.",
                range: "Please enter an integer between -50 and 50.",
                float: "Floats are not supported, please enter integers only."
            },
            num4: {
                required: "Both bounds are required for the vertical axis.",
                number: "Please enter a valid integer.",
                range: "Please enter an integer between -50 and 50.",
                float: "Floats are not supported, please enter integers only."
            },
        },
    });

    $("#inputForm input").on("input", function () {
      if ($("#inputForm").valid()) {
      console.log("form is valid");
      values = captureValues();
      generateTable(values);

      $("#submitButton").prop("disabled", !$("#inputForm").validate().checkForm());
      console.log("input added");
      }
    });

    // Click event for the submit button
    $("#submitButton").click(function () {
        if ($("#inputForm").valid()) {
          console.log("submit clicked");         
          values = captureValues();
          generateTable(values);
          // addTableTab(values);
      
          // Enable the submit button after generating the table
          $("#submitButton").prop("disabled", false);
        }
    });

    // Initialize tabs
    $("#tabs").tabs({
      beforeRemove: function (event, ui) {
        var index = ui.index;
        $(this).tabs("option", "active", index - 1);
        $(ui.panel).remove(); // Remove the tab panel
        $(this).tabs("refresh");
      },
    });

  // Click event for the "Add Tab" button
  $("#add-tab").click(function () {
    if ($("#inputForm").valid()) {
    values = captureValues();
    addTableTab(values);
    }
  });
});


// additional functions
jQuery.validator.addMethod(
  "float",
  function (value, element) {
    console.log("checked float");
    return this.optional(element) || Number.isInteger(parseFloat(value));
  },
);
