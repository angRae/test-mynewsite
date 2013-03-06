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

/*var $ = jQuery;

$(function() {
	$('#edit-argument').change(function() {
		if($(this).val()!='')
			changeLink('index1', $(this).val());
	});
	$('#edit-search-data').bind('keyup', function() {
		if($(this).val()!=0) {
			var replaceData = $(this).val().replace(/ /g, '+');
			changeLink('value1', replaceData);
		}
	});
	$('#edit-specific-result').change(function() {
		if($(this).val()!=0)
			changeLink('results', $(this).val());
	});
});

function changeLink(type, value) {
	var link = $('#edit-acces-link').val();
	if (link) {
		var newLink = '';
		var lengthType = type.length;
		var posType = link.indexOf(type);
		if(posType!='-1') {
			var nextAnd = link.indexOf('&', posType);
			var oldValue = '';
			if (nextAnd!='-1') {
				oldValue = link.substring((posType+lengthType+1), nextAnd);
			} else {
				var lengthLink = link.length;
				oldValue = link.substring((posType+lengthType+1), lengthLink);
			}
			newLink = link.replace(oldValue, value);
		}
		else {
			newLink = link + '&' + type + '=' + value;
		}
		$('#edit-acces-link').empty().append(newLink);
	}
}*/




