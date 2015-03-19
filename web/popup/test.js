$(function () {
    $('.popup-image').magnificPopup({
	type: 'image'
    });

    $('.popup-gallery').magnificPopup({
	delegate: 'a',
	type: 'image',
	tLoading: 'Loading image #%curr%...',
	mainClass: 'mfp-img-mobile',
	gallery: {
	    enabled: true,
	    navigateByImgClick: true,
	    preload: [0,1] // Will preload 0 - before current, and 1 after the current image
	},
	image: {
	    tError: '<a href="%url%">The image #%curr%</a> could not be loaded.',
	    titleSrc: function(item) {
		return item.el.attr('title') + '<small>by Shumin Guo</small>';
	    }
	}
    });

    $('.popup-youtube, .popup-vimeo, .popup-gmaps').magnificPopup({
	disableOn: 700,
	type: 'iframe',
	mainClass: 'mfp-fade',
	removalDelay: 160,
	preloader: false,
	
	fixedContentPos: false
    });
});
