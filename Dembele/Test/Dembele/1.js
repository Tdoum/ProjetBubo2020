function getIdentifiant() {

$.ajax({
		method: 'POST',
		url: "usr/libs/cups/cgi-bin/identifiant.cgi",


		success: function(data){
				if (data.SUCCESS === "OK"){
						identifiant = data.IDENTIFIANT;

				}
				error: function (reponse,status){
					alert("Attention ! identifiant erroné." + reponse);
				};
		}


});

}