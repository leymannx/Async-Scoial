<?php

/**
 * @file
 * Admin page callbacks for the async_social module.
 */

/**
 * Form builder;
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function async_social_settings_form() {

	$form['async_social_buttons'] = array(
		'#type'          => 'checkboxes',
		'#title'         => t('Button types'),
		'#description'   => t('Display these buttons.'),
		'#default_value' => variable_get('async_social_buttons', array()),
		'#options'       => array('like' => 'Facebook Like', 'tweet' => 'Twitter Tweet', 'plusone' => 'Google +1')
	);
	$form['async_social_nodetypes'] = array(
		'#type'          => 'checkboxes',
		'#title'         => t('Node types'),
		'#description'   => t('Display buttons for these node types.'),
		'#default_value' => variable_get('async_social_nodetypes', array()),
		'#options'       => node_type_get_names()
	);
	$form['async_social_viewmodes'] = array(
		'#type'          => 'checkboxes',
		'#title'         => t('View modes'),
		'#description'   => t('Display buttons for these view modes.'),
		'#default_value' => variable_get('async_social_viewmodes', array()),
		'#options'       => _async_social_view_modes()
	);

	return system_settings_form($form);
}

/**
 * Form builder; Configure optional Facebook settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function async_social_facebook_form() {
	module_load_include('inc', 'async_social', 'langcodes');

	$form['async_social_facebook_language'] = array(
		'#type'          => 'select',
		'#title'         => t('Optional: Facebook Language'),
		'#description'   => t('Please choose a language for Facebook\'s button.<br />Will fall back to English if no language is chosen.'),
		'#default_value' => variable_get('async_social_facebook_language', array()),
		'#options'       => async_social_langcode_options('facebook')
	);
	$form['async_social_facebook_share'] = array(
		'#type'          => 'checkbox',
		'#title'         => t('Facebook Share Button'),
		'#default_value' => variable_get('async_social_facebook_share', FALSE),
	);
	$form['async_social_facebook_appid'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Optional: Facebook AppID'),
		'#description'   => t('Enter a Facebook AppID if you have one. It\'s not necessary to make the button work.<br />You only need it for tracking and customised button actions within your Facebook page.'),
		'#default_value' => variable_get('async_social_facebook_appid', ''),
	);

	return system_settings_form($form);
}

/**
 * Form builder; Configure optional Twitter settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function async_social_twitter_form() {
	module_load_include('inc', 'async_social', 'langcodes');

	$form['async_social_twitter_language'] = array(
		'#type'          => 'select',
		'#title'         => t('Optional: Twitter Language'),
		'#description'   => t('Please choose a language for Twitter\'s button.<br />Will fall back to English if no language is chosen.'),
		'#default_value' => variable_get('async_social_twitter_language', array()),
		'#options'       => async_social_langcode_options('twitter')
	);
	$form['async_social_twitter_via'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Optional: Twitter Username (without @-symbol)'),
		'#description'   => t('Appears appended to Tweet text as "via @username". It\'s not necessary to make the button work.<br />You only need it for referencing the tweets to you.'),
		'#default_value' => variable_get('async_social_twitter_via', ''),
	);
	$form['async_social_twitter_related'] = array(
		'#type'          => 'textfield',
		'#title'         => t('Optional: Twitter Related (without @-symbols)'),
		'#description'   => t('A comma-separated list (with no spaces) of Twitter usernames related to the content of the shared URI.<br /> Not necessary to make the button work. An included Twitter account may appear in a list of recommended accounts to follow.'),
		'#default_value' => variable_get('async_social_twitter_related', ''),
	);

	return system_settings_form($form);
}

/**
 * Form builder; Configure optional Google settings.
 *
 * @ingroup forms
 * @see system_settings_form()
 */
function async_social_google_form() {
	module_load_include('inc', 'async_social', 'langcodes');

	$form['async_social_google_language'] = array(
		'#type'          => 'select',
		'#title'         => t('Optional: Google Language'),
		'#description'   => t('Please choose a language for Google\'s button.<br />Will fall back to English if no language is chosen.'),
		'#default_value' => variable_get('async_social_google_language', array()),
		'#options'       => async_social_langcode_options('google')
	);

	return system_settings_form($form);
}