/**
 * @file 
 * isbndb.js
 * Contains javascript for isbndb form.
 */

(function ($) {
Drupal.behaviors.isbndb = {
	attach: function(context, settings) { 
  	$(context).find('#edit-argument').change(function() {
  		newLink();
  	});
  	$(context).find('#edit-search-data').bind('keyup', function() {
  		newLink();
  	});
  	$(context).find('#edit-specific-result').change(function() {
  		newLink();
  	});
  
	/*$('#map div div div svg g').delegate('image', 'click', function () {
    return false;
	});*/
	}
}
function newLink() {
	var link = $('input:hidden[name=base_acces_link]').val();
	if (link) {
		var newL = link;
		var argument = $('#edit-argument').val();
		var searchData = $('#edit-search-data').val().replace(/ /g, '+');
		var specificRes = $('#edit-specific-result').val();
		if (specificRes!=0) newL += '&results=' + specificRes;
    if (argument!='') newL += '&index1=' + argument;
    if ($.trim(searchData)!='') newL += '&value1=' + searchData;
    $('#edit-acces-link').empty().append(newL);
	}
}
})(jQuery);






