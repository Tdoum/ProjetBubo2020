  
$(function() {
    $("#save").on('click', saveSelectedValeur);
    $('button').on('click', show);
});




function saveSelectedValeur()
{
	formData = new FormData();
        //formData.append('identifiant', identifiant);
	formData.append('theCar', $('#cars').val()); 
    
            var request = new XMLHttpRequest();
            request.onreadystatechange = function() {
                if (this.readyState === 4 && this.status === 200) {
                    console.log("It's OK");
                }
            };
            
            request.open("POST", "/cgi-bin/montest.cgi");
            request.send(formData);

}

function show(){
    var khd = "audi" ;
     $.get("test.txt", function(result){
      if(result=="audi"){
//document.getElementById( "cars").selectedIndex = "audi"; 
         $('#cars').val(result);
         $('#cars').selectmenu('refresh');
  console.log("salut");
}
    });
  }







