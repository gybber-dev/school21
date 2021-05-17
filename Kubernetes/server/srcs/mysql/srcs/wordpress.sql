-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Host: sql-svc:3306
-- Generation Time: May 17, 2021 at 01:03 PM
-- Server version: 10.1.41-MariaDB
-- PHP Version: 7.1.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `wordpress`
--

-- --------------------------------------------------------

--
-- Table structure for table `wp_commentmeta`
--

CREATE TABLE `wp_commentmeta` (
  `meta_id` bigint(20) UNSIGNED NOT NULL,
  `comment_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `meta_key` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `meta_value` longtext COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `wp_comments`
--

CREATE TABLE `wp_comments` (
  `comment_ID` bigint(20) UNSIGNED NOT NULL,
  `comment_post_ID` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `comment_author` tinytext COLLATE utf8mb4_unicode_ci NOT NULL,
  `comment_author_email` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `comment_author_url` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `comment_author_IP` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `comment_date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `comment_date_gmt` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `comment_content` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `comment_karma` int(11) NOT NULL DEFAULT '0',
  `comment_approved` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '1',
  `comment_agent` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `comment_type` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'comment',
  `comment_parent` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `user_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_comments`
--

INSERT INTO `wp_comments` (`comment_ID`, `comment_post_ID`, `comment_author`, `comment_author_email`, `comment_author_url`, `comment_author_IP`, `comment_date`, `comment_date_gmt`, `comment_content`, `comment_karma`, `comment_approved`, `comment_agent`, `comment_type`, `comment_parent`, `user_id`) VALUES
(1, 1, 'A WordPress Commenter', 'wapuu@wordpress.example', 'https://wordpress.org/', '', '2021-04-24 16:01:23', '2021-04-24 16:01:23', 'Hi, this is a comment.\nTo get started with moderating, editing, and deleting comments, please visit the Comments screen in the dashboard.\nCommenter avatars come from <a href=\"https://gravatar.com\">Gravatar</a>.', 0, 'post-trashed', '', 'comment', 0, 0);

-- --------------------------------------------------------

--
-- Table structure for table `wp_links`
--

CREATE TABLE `wp_links` (
  `link_id` bigint(20) UNSIGNED NOT NULL,
  `link_url` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_name` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_image` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_target` varchar(25) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_description` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_visible` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'Y',
  `link_owner` bigint(20) UNSIGNED NOT NULL DEFAULT '1',
  `link_rating` int(11) NOT NULL DEFAULT '0',
  `link_updated` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `link_rel` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `link_notes` mediumtext COLLATE utf8mb4_unicode_ci NOT NULL,
  `link_rss` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `wp_options`
--

CREATE TABLE `wp_options` (
  `option_id` bigint(20) UNSIGNED NOT NULL,
  `option_name` varchar(191) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `option_value` longtext COLLATE utf8mb4_unicode_ci NOT NULL,
  `autoload` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'yes'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_options`
--

INSERT INTO `wp_options` (`option_id`, `option_name`, `option_value`, `autoload`) VALUES
(1, 'siteurl', 'http://192.168.99.101:5050', 'yes'),
(2, 'home', 'http://192.168.99.101:5050', 'yes'),
(3, 'blogname', 'Yeschall&#039;s services', 'yes'),
(4, 'blogdescription', '', 'yes'),
(5, 'users_can_register', '0', 'yes'),
(6, 'admin_email', 'aaa@mail.com', 'yes'),
(7, 'start_of_week', '1', 'yes'),
(8, 'use_balanceTags', '0', 'yes'),
(9, 'use_smilies', '1', 'yes'),
(10, 'require_name_email', '1', 'yes'),
(11, 'comments_notify', '1', 'yes'),
(12, 'posts_per_rss', '10', 'yes'),
(13, 'rss_use_excerpt', '0', 'yes'),
(14, 'mailserver_url', 'mail.example.com', 'yes'),
(15, 'mailserver_login', 'login@example.com', 'yes'),
(16, 'mailserver_pass', 'password', 'yes'),
(17, 'mailserver_port', '110', 'yes'),
(18, 'default_category', '1', 'yes'),
(19, 'default_comment_status', 'open', 'yes'),
(20, 'default_ping_status', 'open', 'yes'),
(21, 'default_pingback_flag', '1', 'yes'),
(22, 'posts_per_page', '10', 'yes'),
(23, 'date_format', 'F j, Y', 'yes'),
(24, 'time_format', 'g:i a', 'yes'),
(25, 'links_updated_date_format', 'F j, Y g:i a', 'yes'),
(26, 'comment_moderation', '0', 'yes'),
(27, 'moderation_notify', '1', 'yes'),
(28, 'permalink_structure', '', 'yes'),
(29, 'rewrite_rules', '', 'yes'),
(30, 'hack_file', '0', 'yes'),
(31, 'blog_charset', 'UTF-8', 'yes'),
(32, 'moderation_keys', '', 'no'),
(33, 'active_plugins', 'a:0:{}', 'yes'),
(34, 'category_base', '', 'yes'),
(35, 'ping_sites', 'http://rpc.pingomatic.com/', 'yes'),
(36, 'comment_max_links', '2', 'yes'),
(37, 'gmt_offset', '0', 'yes'),
(38, 'default_email_category', '1', 'yes'),
(39, 'recently_edited', 'a:2:{i:0;s:65:\"/var/www/localhost/wordpress/wp-content/themes/onepress/style.css\";i:1;s:0:\"\";}', 'no'),
(40, 'template', 'minamaze', 'yes'),
(41, 'stylesheet', 'minamaze', 'yes'),
(42, 'comment_registration', '0', 'yes'),
(43, 'html_type', 'text/html', 'yes'),
(44, 'use_trackback', '0', 'yes'),
(45, 'default_role', 'subscriber', 'yes'),
(46, 'db_version', '49752', 'yes'),
(47, 'uploads_use_yearmonth_folders', '1', 'yes'),
(48, 'upload_path', '', 'yes'),
(49, 'blog_public', '1', 'yes'),
(50, 'default_link_category', '2', 'yes'),
(51, 'show_on_front', 'posts', 'yes'),
(52, 'tag_base', '', 'yes'),
(53, 'show_avatars', '1', 'yes'),
(54, 'avatar_rating', 'G', 'yes'),
(55, 'upload_url_path', '', 'yes'),
(56, 'thumbnail_size_w', '150', 'yes'),
(57, 'thumbnail_size_h', '150', 'yes'),
(58, 'thumbnail_crop', '1', 'yes'),
(59, 'medium_size_w', '300', 'yes'),
(60, 'medium_size_h', '300', 'yes'),
(61, 'avatar_default', 'mystery', 'yes'),
(62, 'large_size_w', '1024', 'yes'),
(63, 'large_size_h', '1024', 'yes'),
(64, 'image_default_link_type', 'none', 'yes'),
(65, 'image_default_size', '', 'yes'),
(66, 'image_default_align', '', 'yes'),
(67, 'close_comments_for_old_posts', '0', 'yes'),
(68, 'close_comments_days_old', '14', 'yes'),
(69, 'thread_comments', '1', 'yes'),
(70, 'thread_comments_depth', '5', 'yes'),
(71, 'page_comments', '0', 'yes'),
(72, 'comments_per_page', '50', 'yes'),
(73, 'default_comments_page', 'newest', 'yes'),
(74, 'comment_order', 'asc', 'yes'),
(75, 'sticky_posts', 'a:0:{}', 'yes'),
(76, 'widget_categories', 'a:2:{i:2;a:4:{s:5:\"title\";s:0:\"\";s:5:\"count\";i:0;s:12:\"hierarchical\";i:0;s:8:\"dropdown\";i:0;}s:12:\"_multiwidget\";i:1;}', 'yes'),
(77, 'widget_text', 'a:2:{i:1;a:0:{}s:12:\"_multiwidget\";i:1;}', 'yes'),
(78, 'widget_rss', 'a:2:{i:1;a:0:{}s:12:\"_multiwidget\";i:1;}', 'yes'),
(79, 'uninstall_plugins', 'a:0:{}', 'no'),
(80, 'timezone_string', '', 'yes'),
(81, 'page_for_posts', '0', 'yes'),
(82, 'page_on_front', '0', 'yes'),
(83, 'default_post_format', '0', 'yes'),
(84, 'link_manager_enabled', '0', 'yes'),
(85, 'finished_splitting_shared_terms', '1', 'yes'),
(86, 'site_icon', '0', 'yes'),
(87, 'medium_large_size_w', '768', 'yes'),
(88, 'medium_large_size_h', '0', 'yes'),
(89, 'wp_page_for_privacy_policy', '3', 'yes'),
(90, 'show_comments_cookies_opt_in', '1', 'yes'),
(91, 'admin_email_lifespan', '1634832083', 'yes'),
(92, 'disallowed_keys', '', 'no'),
(93, 'comment_previously_approved', '1', 'yes'),
(94, 'auto_plugin_theme_update_emails', 'a:0:{}', 'no'),
(95, 'auto_update_core_dev', 'enabled', 'yes'),
(96, 'auto_update_core_minor', 'enabled', 'yes'),
(97, 'auto_update_core_major', 'enabled', 'yes'),
(98, 'initial_db_version', '49752', 'yes'),
(99, 'wp_user_roles', 'a:5:{s:13:\"administrator\";a:2:{s:4:\"name\";s:13:\"Administrator\";s:12:\"capabilities\";a:61:{s:13:\"switch_themes\";b:1;s:11:\"edit_themes\";b:1;s:16:\"activate_plugins\";b:1;s:12:\"edit_plugins\";b:1;s:10:\"edit_users\";b:1;s:10:\"edit_files\";b:1;s:14:\"manage_options\";b:1;s:17:\"moderate_comments\";b:1;s:17:\"manage_categories\";b:1;s:12:\"manage_links\";b:1;s:12:\"upload_files\";b:1;s:6:\"import\";b:1;s:15:\"unfiltered_html\";b:1;s:10:\"edit_posts\";b:1;s:17:\"edit_others_posts\";b:1;s:20:\"edit_published_posts\";b:1;s:13:\"publish_posts\";b:1;s:10:\"edit_pages\";b:1;s:4:\"read\";b:1;s:8:\"level_10\";b:1;s:7:\"level_9\";b:1;s:7:\"level_8\";b:1;s:7:\"level_7\";b:1;s:7:\"level_6\";b:1;s:7:\"level_5\";b:1;s:7:\"level_4\";b:1;s:7:\"level_3\";b:1;s:7:\"level_2\";b:1;s:7:\"level_1\";b:1;s:7:\"level_0\";b:1;s:17:\"edit_others_pages\";b:1;s:20:\"edit_published_pages\";b:1;s:13:\"publish_pages\";b:1;s:12:\"delete_pages\";b:1;s:19:\"delete_others_pages\";b:1;s:22:\"delete_published_pages\";b:1;s:12:\"delete_posts\";b:1;s:19:\"delete_others_posts\";b:1;s:22:\"delete_published_posts\";b:1;s:20:\"delete_private_posts\";b:1;s:18:\"edit_private_posts\";b:1;s:18:\"read_private_posts\";b:1;s:20:\"delete_private_pages\";b:1;s:18:\"edit_private_pages\";b:1;s:18:\"read_private_pages\";b:1;s:12:\"delete_users\";b:1;s:12:\"create_users\";b:1;s:17:\"unfiltered_upload\";b:1;s:14:\"edit_dashboard\";b:1;s:14:\"update_plugins\";b:1;s:14:\"delete_plugins\";b:1;s:15:\"install_plugins\";b:1;s:13:\"update_themes\";b:1;s:14:\"install_themes\";b:1;s:11:\"update_core\";b:1;s:10:\"list_users\";b:1;s:12:\"remove_users\";b:1;s:13:\"promote_users\";b:1;s:18:\"edit_theme_options\";b:1;s:13:\"delete_themes\";b:1;s:6:\"export\";b:1;}}s:6:\"editor\";a:2:{s:4:\"name\";s:6:\"Editor\";s:12:\"capabilities\";a:34:{s:17:\"moderate_comments\";b:1;s:17:\"manage_categories\";b:1;s:12:\"manage_links\";b:1;s:12:\"upload_files\";b:1;s:15:\"unfiltered_html\";b:1;s:10:\"edit_posts\";b:1;s:17:\"edit_others_posts\";b:1;s:20:\"edit_published_posts\";b:1;s:13:\"publish_posts\";b:1;s:10:\"edit_pages\";b:1;s:4:\"read\";b:1;s:7:\"level_7\";b:1;s:7:\"level_6\";b:1;s:7:\"level_5\";b:1;s:7:\"level_4\";b:1;s:7:\"level_3\";b:1;s:7:\"level_2\";b:1;s:7:\"level_1\";b:1;s:7:\"level_0\";b:1;s:17:\"edit_others_pages\";b:1;s:20:\"edit_published_pages\";b:1;s:13:\"publish_pages\";b:1;s:12:\"delete_pages\";b:1;s:19:\"delete_others_pages\";b:1;s:22:\"delete_published_pages\";b:1;s:12:\"delete_posts\";b:1;s:19:\"delete_others_posts\";b:1;s:22:\"delete_published_posts\";b:1;s:20:\"delete_private_posts\";b:1;s:18:\"edit_private_posts\";b:1;s:18:\"read_private_posts\";b:1;s:20:\"delete_private_pages\";b:1;s:18:\"edit_private_pages\";b:1;s:18:\"read_private_pages\";b:1;}}s:6:\"author\";a:2:{s:4:\"name\";s:6:\"Author\";s:12:\"capabilities\";a:10:{s:12:\"upload_files\";b:1;s:10:\"edit_posts\";b:1;s:20:\"edit_published_posts\";b:1;s:13:\"publish_posts\";b:1;s:4:\"read\";b:1;s:7:\"level_2\";b:1;s:7:\"level_1\";b:1;s:7:\"level_0\";b:1;s:12:\"delete_posts\";b:1;s:22:\"delete_published_posts\";b:1;}}s:11:\"contributor\";a:2:{s:4:\"name\";s:11:\"Contributor\";s:12:\"capabilities\";a:5:{s:10:\"edit_posts\";b:1;s:4:\"read\";b:1;s:7:\"level_1\";b:1;s:7:\"level_0\";b:1;s:12:\"delete_posts\";b:1;}}s:10:\"subscriber\";a:2:{s:4:\"name\";s:10:\"Subscriber\";s:12:\"capabilities\";a:2:{s:4:\"read\";b:1;s:7:\"level_0\";b:1;}}}', 'yes'),
(100, 'fresh_site', '0', 'yes'),
(101, 'widget_search', 'a:2:{i:2;a:1:{s:5:\"title\";s:0:\"\";}s:12:\"_multiwidget\";i:1;}', 'yes'),
(102, 'widget_recent-posts', 'a:2:{i:2;a:2:{s:5:\"title\";s:0:\"\";s:6:\"number\";i:5;}s:12:\"_multiwidget\";i:1;}', 'yes'),
(103, 'widget_recent-comments', 'a:2:{i:2;a:2:{s:5:\"title\";s:0:\"\";s:6:\"number\";i:5;}s:12:\"_multiwidget\";i:1;}', 'yes'),
(104, 'widget_archives', 'a:2:{i:2;a:3:{s:5:\"title\";s:0:\"\";s:5:\"count\";i:0;s:8:\"dropdown\";i:0;}s:12:\"_multiwidget\";i:1;}', 'yes'),
(105, 'widget_meta', 'a:2:{i:2;a:1:{s:5:\"title\";s:0:\"\";}s:12:\"_multiwidget\";i:1;}', 'yes'),
(106, 'sidebars_widgets', 'a:9:{s:19:\"wp_inactive_widgets\";a:0:{}s:9:\"sidebar-1\";a:6:{i:0;s:8:\"search-2\";i:1;s:14:\"recent-posts-2\";i:2;s:17:\"recent-comments-2\";i:3;s:10:\"archives-2\";i:4;s:12:\"categories-2\";i:5;s:6:\"meta-2\";}s:9:\"footer-w1\";a:0:{}s:9:\"footer-w2\";a:0:{}s:9:\"footer-w3\";a:0:{}s:9:\"footer-w4\";a:0:{}s:9:\"footer-w5\";a:0:{}s:9:\"footer-w6\";a:0:{}s:13:\"array_version\";i:3;}', 'yes'),
(107, 'cron', 'a:7:{i:1619280105;a:6:{s:32:\"recovery_mode_clean_expired_keys\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:5:\"daily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:86400;}}s:18:\"wp_https_detection\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:10:\"twicedaily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:43200;}}s:34:\"wp_privacy_delete_old_export_files\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:6:\"hourly\";s:4:\"args\";a:0:{}s:8:\"interval\";i:3600;}}s:16:\"wp_version_check\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:10:\"twicedaily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:43200;}}s:17:\"wp_update_plugins\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:10:\"twicedaily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:43200;}}s:16:\"wp_update_themes\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:10:\"twicedaily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:43200;}}}i:1619280122;a:2:{s:19:\"wp_scheduled_delete\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:5:\"daily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:86400;}}s:25:\"delete_expired_transients\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:5:\"daily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:86400;}}}i:1619280126;a:1:{s:30:\"wp_scheduled_auto_draft_delete\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:5:\"daily\";s:4:\"args\";a:0:{}s:8:\"interval\";i:86400;}}}i:1619280182;a:1:{s:28:\"wp_update_comment_type_batch\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:2:{s:8:\"schedule\";b:0;s:4:\"args\";a:0:{}}}}i:1619366505;a:1:{s:30:\"wp_site_health_scheduled_check\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:3:{s:8:\"schedule\";s:6:\"weekly\";s:4:\"args\";a:0:{}s:8:\"interval\";i:604800;}}}i:1621250564;a:1:{s:8:\"do_pings\";a:1:{s:32:\"40cd750bba9870f18aada2478b24840a\";a:2:{s:8:\"schedule\";b:0;s:4:\"args\";a:0:{}}}}s:7:\"version\";i:2;}', 'yes'),
(108, 'widget_pages', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(109, 'widget_calendar', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(110, 'widget_media_audio', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(111, 'widget_media_image', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(112, 'widget_media_gallery', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(113, 'widget_media_video', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(114, 'widget_tag_cloud', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(115, 'widget_nav_menu', 'a:1:{s:12:\"_multiwidget\";i:1;}', 'yes'),
(116, 'widget_custom_html', 'a:2:{s:12:\"_multiwidget\";i:1;i:3;a:2:{s:5:\"title\";s:8:\"asdfasdf\";s:7:\"content\";s:0:\"\";}}', 'yes'),
(117, '_transient_doing_cron', '1621256475.4903960227966308593750', 'yes'),
(118, 'theme_mods_twentytwentyone', 'a:2:{s:18:\"custom_css_post_id\";i:-1;s:16:\"sidebars_widgets\";a:2:{s:4:\"time\";i:1621253007;s:4:\"data\";a:3:{s:19:\"wp_inactive_widgets\";a:0:{}s:9:\"sidebar-1\";a:3:{i:0;s:8:\"search-2\";i:1;s:14:\"recent-posts-2\";i:2;s:17:\"recent-comments-2\";}s:9:\"sidebar-2\";a:3:{i:0;s:10:\"archives-2\";i:1;s:12:\"categories-2\";i:2;s:6:\"meta-2\";}}}}', 'yes'),
(119, '_site_transient_update_core', 'O:8:\"stdClass\":4:{s:7:\"updates\";a:1:{i:0;O:8:\"stdClass\":10:{s:8:\"response\";s:6:\"latest\";s:8:\"download\";s:59:\"https://downloads.wordpress.org/release/wordpress-5.7.2.zip\";s:6:\"locale\";s:5:\"en_US\";s:8:\"packages\";O:8:\"stdClass\":5:{s:4:\"full\";s:59:\"https://downloads.wordpress.org/release/wordpress-5.7.2.zip\";s:10:\"no_content\";s:70:\"https://downloads.wordpress.org/release/wordpress-5.7.2-no-content.zip\";s:11:\"new_bundled\";s:71:\"https://downloads.wordpress.org/release/wordpress-5.7.2-new-bundled.zip\";s:7:\"partial\";s:0:\"\";s:8:\"rollback\";s:0:\"\";}s:7:\"current\";s:5:\"5.7.2\";s:7:\"version\";s:5:\"5.7.2\";s:11:\"php_version\";s:6:\"5.6.20\";s:13:\"mysql_version\";s:3:\"5.0\";s:11:\"new_bundled\";s:3:\"5.6\";s:15:\"partial_version\";s:0:\"\";}}s:12:\"last_checked\";i:1621253440;s:15:\"version_checked\";s:5:\"5.7.2\";s:12:\"translations\";a:0:{}}', 'no'),
(120, '_site_transient_update_plugins', 'O:8:\"stdClass\":4:{s:12:\"last_checked\";i:1621253440;s:8:\"response\";a:0:{}s:12:\"translations\";a:0:{}s:9:\"no_update\";a:2:{s:19:\"akismet/akismet.php\";O:8:\"stdClass\":9:{s:2:\"id\";s:21:\"w.org/plugins/akismet\";s:4:\"slug\";s:7:\"akismet\";s:6:\"plugin\";s:19:\"akismet/akismet.php\";s:11:\"new_version\";s:5:\"4.1.9\";s:3:\"url\";s:38:\"https://wordpress.org/plugins/akismet/\";s:7:\"package\";s:56:\"https://downloads.wordpress.org/plugin/akismet.4.1.9.zip\";s:5:\"icons\";a:2:{s:2:\"2x\";s:59:\"https://ps.w.org/akismet/assets/icon-256x256.png?rev=969272\";s:2:\"1x\";s:59:\"https://ps.w.org/akismet/assets/icon-128x128.png?rev=969272\";}s:7:\"banners\";a:1:{s:2:\"1x\";s:61:\"https://ps.w.org/akismet/assets/banner-772x250.jpg?rev=479904\";}s:11:\"banners_rtl\";a:0:{}}s:9:\"hello.php\";O:8:\"stdClass\":9:{s:2:\"id\";s:25:\"w.org/plugins/hello-dolly\";s:4:\"slug\";s:11:\"hello-dolly\";s:6:\"plugin\";s:9:\"hello.php\";s:11:\"new_version\";s:5:\"1.7.2\";s:3:\"url\";s:42:\"https://wordpress.org/plugins/hello-dolly/\";s:7:\"package\";s:60:\"https://downloads.wordpress.org/plugin/hello-dolly.1.7.2.zip\";s:5:\"icons\";a:2:{s:2:\"2x\";s:64:\"https://ps.w.org/hello-dolly/assets/icon-256x256.jpg?rev=2052855\";s:2:\"1x\";s:64:\"https://ps.w.org/hello-dolly/assets/icon-128x128.jpg?rev=2052855\";}s:7:\"banners\";a:1:{s:2:\"1x\";s:66:\"https://ps.w.org/hello-dolly/assets/banner-772x250.jpg?rev=2052855\";}s:11:\"banners_rtl\";a:0:{}}}}', 'no'),
(128, 'can_compress_scripts', '1', 'no'),
(135, '_site_transient_timeout_browser_9c8b1062a443abbe33f976bf51b91fcb', '1621853542', 'no'),
(136, '_site_transient_browser_9c8b1062a443abbe33f976bf51b91fcb', 'a:10:{s:4:\"name\";s:6:\"Chrome\";s:7:\"version\";s:13:\"88.0.4324.150\";s:8:\"platform\";s:9:\"Macintosh\";s:10:\"update_url\";s:29:\"https://www.google.com/chrome\";s:7:\"img_src\";s:43:\"http://s.w.org/images/browsers/chrome.png?1\";s:11:\"img_src_ssl\";s:44:\"https://s.w.org/images/browsers/chrome.png?1\";s:15:\"current_version\";s:2:\"18\";s:7:\"upgrade\";b:0;s:8:\"insecure\";b:0;s:6:\"mobile\";b:0;}', 'no'),
(137, '_site_transient_timeout_php_check_97f83d63b8a66f6e8c057d89a83d8845', '1621853543', 'no'),
(138, '_site_transient_php_check_97f83d63b8a66f6e8c057d89a83d8845', 'a:5:{s:19:\"recommended_version\";s:3:\"7.4\";s:15:\"minimum_version\";s:6:\"5.6.20\";s:12:\"is_supported\";b:0;s:9:\"is_secure\";b:0;s:13:\"is_acceptable\";b:0;}', 'no'),
(139, '_transient_timeout_dash_v2_88ae138922fe95674369b1cb3d215a2b', '1621291954', 'no'),
(140, '_transient_dash_v2_88ae138922fe95674369b1cb3d215a2b', '<div class=\"rss-widget\"><p><strong>RSS Error:</strong> XML or PCRE extensions not loaded!</p></div><div class=\"rss-widget\"><p><strong>RSS Error:</strong> XML or PCRE extensions not loaded!</p></div>', 'no'),
(141, '_site_transient_timeout_community-events-e2f2ed925cc0dc7eddd67ec58c0404fa', '1621291954', 'no'),
(142, '_site_transient_community-events-e2f2ed925cc0dc7eddd67ec58c0404fa', 'a:4:{s:9:\"sandboxed\";b:0;s:5:\"error\";N;s:8:\"location\";a:1:{s:2:\"ip\";s:10:\"172.17.0.0\";}s:6:\"events\";a:1:{i:0;a:10:{s:4:\"type\";s:8:\"wordcamp\";s:5:\"title\";s:30:\"WordCamp Northeast Ohio Region\";s:3:\"url\";s:30:\"https://neo.wordcamp.org/2021/\";s:6:\"meetup\";N;s:10:\"meetup_url\";N;s:4:\"date\";s:19:\"2021-05-21 00:00:00\";s:8:\"end_date\";s:19:\"2021-05-23 00:00:00\";s:20:\"start_unix_timestamp\";i:1621569600;s:18:\"end_unix_timestamp\";i:1621742400;s:8:\"location\";a:4:{s:8:\"location\";s:6:\"Online\";s:7:\"country\";s:2:\"US\";s:8:\"latitude\";d:41.2617873;s:9:\"longitude\";d:-81.1637245;}}}}', 'no'),
(147, 'current_theme', 'Minamaze', 'yes'),
(148, 'theme_mods_onepress', 'a:4:{i:0;b:0;s:18:\"nav_menu_locations\";a:0:{}s:18:\"custom_css_post_id\";i:-1;s:16:\"sidebars_widgets\";a:2:{s:4:\"time\";i:1621253453;s:4:\"data\";a:6:{s:19:\"wp_inactive_widgets\";a:0:{}s:9:\"sidebar-1\";a:6:{i:0;s:8:\"search-2\";i:1;s:14:\"recent-posts-2\";i:2;s:17:\"recent-comments-2\";i:3;s:10:\"archives-2\";i:4;s:12:\"categories-2\";i:5;s:6:\"meta-2\";}s:8:\"footer-1\";a:0:{}s:8:\"footer-2\";a:0:{}s:8:\"footer-3\";a:0:{}s:8:\"footer-4\";a:0:{}}}}', 'yes'),
(149, 'theme_switched', '', 'yes'),
(155, '_site_transient_update_themes', 'O:8:\"stdClass\":5:{s:12:\"last_checked\";i:1621253445;s:7:\"checked\";a:5:{s:8:\"minamaze\";s:5:\"1.7.8\";s:8:\"onepress\";s:5:\"2.2.7\";s:14:\"twentynineteen\";s:3:\"2.0\";s:12:\"twentytwenty\";s:3:\"1.7\";s:15:\"twentytwentyone\";s:3:\"1.3\";}s:8:\"response\";a:0:{}s:9:\"no_update\";a:5:{s:8:\"minamaze\";a:6:{s:5:\"theme\";s:8:\"minamaze\";s:11:\"new_version\";s:5:\"1.7.8\";s:3:\"url\";s:38:\"https://wordpress.org/themes/minamaze/\";s:7:\"package\";s:56:\"https://downloads.wordpress.org/theme/minamaze.1.7.8.zip\";s:8:\"requires\";s:3:\"4.7\";s:12:\"requires_php\";s:5:\"5.6.0\";}s:8:\"onepress\";a:6:{s:5:\"theme\";s:8:\"onepress\";s:11:\"new_version\";s:5:\"2.2.7\";s:3:\"url\";s:38:\"https://wordpress.org/themes/onepress/\";s:7:\"package\";s:56:\"https://downloads.wordpress.org/theme/onepress.2.2.7.zip\";s:8:\"requires\";b:0;s:12:\"requires_php\";s:3:\"5.6\";}s:14:\"twentynineteen\";a:6:{s:5:\"theme\";s:14:\"twentynineteen\";s:11:\"new_version\";s:3:\"2.0\";s:3:\"url\";s:44:\"https://wordpress.org/themes/twentynineteen/\";s:7:\"package\";s:60:\"https://downloads.wordpress.org/theme/twentynineteen.2.0.zip\";s:8:\"requires\";s:5:\"4.9.6\";s:12:\"requires_php\";s:5:\"5.2.4\";}s:12:\"twentytwenty\";a:6:{s:5:\"theme\";s:12:\"twentytwenty\";s:11:\"new_version\";s:3:\"1.7\";s:3:\"url\";s:42:\"https://wordpress.org/themes/twentytwenty/\";s:7:\"package\";s:58:\"https://downloads.wordpress.org/theme/twentytwenty.1.7.zip\";s:8:\"requires\";s:3:\"4.7\";s:12:\"requires_php\";s:5:\"5.2.4\";}s:15:\"twentytwentyone\";a:6:{s:5:\"theme\";s:15:\"twentytwentyone\";s:11:\"new_version\";s:3:\"1.3\";s:3:\"url\";s:45:\"https://wordpress.org/themes/twentytwentyone/\";s:7:\"package\";s:61:\"https://downloads.wordpress.org/theme/twentytwentyone.1.3.zip\";s:8:\"requires\";s:3:\"5.3\";s:12:\"requires_php\";s:3:\"5.6\";}}s:12:\"translations\";a:0:{}}', 'no'),
(157, 'theme_mods_minamaze', 'a:4:{i:0;b:0;s:18:\"nav_menu_locations\";a:1:{s:15:\"pre_header_menu\";i:0;}s:18:\"custom_css_post_id\";i:-1;s:16:\"background_color\";s:6:\"cecece\";}', 'yes'),
(159, 'category_children', 'a:0:{}', 'yes'),
(166, 'thinkup_redux_variables', 'a:22:{s:31:\"thinkup_homepage_section1_title\";s:10:\"Check Page\";s:30:\"thinkup_homepage_section1_desc\";s:31:\"Click below to open the page ya\";s:30:\"thinkup_homepage_section1_link\";i:33;s:30:\"thinkup_homepage_section2_desc\";s:28:\"Click below to open the page\";s:30:\"thinkup_homepage_section3_desc\";s:28:\"Click below to open the page\";s:31:\"thinkup_homepage_section2_title\";s:10:\"phpMyAdmin\";s:31:\"thinkup_homepage_section3_title\";s:7:\"Grafana\";s:29:\"thinkup_homepage_sliderswitch\";s:7:\"option3\";s:35:\"thinkup_homepage_sliderimage1_title\";s:5:\"title\";s:34:\"thinkup_homepage_sliderimage1_desc\";s:8:\"asdfasdf\";s:34:\"thinkup_homepage_sliderimage1_link\";i:2;s:28:\"thinkup_homepage_introswitch\";b:0;s:23:\"thinkup_homepage_layout\";s:7:\"option1\";s:32:\"thinkup_homepage_introactionlink\";s:7:\"option3\";s:19:\"thinkup_blog_layout\";s:7:\"option1\";s:23:\"thinkup_blog_postswitch\";s:7:\"option3\";s:19:\"thinkup_post_layout\";s:7:\"option1\";s:22:\"thinkup_general_layout\";s:7:\"option1\";s:21:\"thinkup_footer_layout\";s:7:\"option1\";s:27:\"thinkup_footer_widgetswitch\";b:1;s:30:\"thinkup_homepage_section2_link\";i:35;s:30:\"thinkup_homepage_section3_link\";i:31;}', 'yes'),
(203, '_site_transient_timeout_theme_roots', '1621257172', 'no'),
(204, '_site_transient_theme_roots', 'a:5:{s:8:\"minamaze\";s:7:\"/themes\";s:8:\"onepress\";s:7:\"/themes\";s:14:\"twentynineteen\";s:7:\"/themes\";s:12:\"twentytwenty\";s:7:\"/themes\";s:15:\"twentytwentyone\";s:7:\"/themes\";}', 'no'),
(227, '_transient_is_multi_author', '0', 'yes'),
(228, '_transient_thinkup_transient_categories', '1', 'yes');

-- --------------------------------------------------------

--
-- Table structure for table `wp_postmeta`
--

CREATE TABLE `wp_postmeta` (
  `meta_id` bigint(20) UNSIGNED NOT NULL,
  `post_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `meta_key` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `meta_value` longtext COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_postmeta`
--

INSERT INTO `wp_postmeta` (`meta_id`, `post_id`, `meta_key`, `meta_value`) VALUES
(1, 2, '_wp_page_template', 'default'),
(2, 3, '_wp_page_template', 'default'),
(3, 2, '_edit_lock', '1621255563:1'),
(4, 1, '_edit_lock', '1621255964:1'),
(5, 1, '_pingme', '1'),
(6, 1, '_encloseme', '1'),
(7, 1, '_oembed_62dd566b27bcb2938eba6852ca485a46', '{{unknown}}'),
(8, 3, '_edit_lock', '1621253083:1'),
(9, 2, '_edit_last', '1'),
(10, 2, '_hide_page_title', ''),
(11, 2, '_hide_header', ''),
(12, 2, '_hide_footer', ''),
(13, 2, '_hide_breadcrumb', ''),
(14, 2, '_cover', ''),
(15, 2, '_show_excerpt', ''),
(16, 2, '_wc_apply_product', ''),
(17, 20, '_edit_lock', '1621253973:1'),
(18, 20, '_wp_trash_meta_status', 'publish'),
(19, 20, '_wp_trash_meta_time', '1621253992'),
(20, 21, '_edit_lock', '1621254285:1'),
(21, 21, '_wp_trash_meta_status', 'publish'),
(22, 21, '_wp_trash_meta_time', '1621254314'),
(23, 22, '_edit_lock', '1621254453:1'),
(24, 22, '_wp_trash_meta_status', 'publish'),
(25, 22, '_wp_trash_meta_time', '1621254462'),
(26, 23, '_wp_trash_meta_status', 'publish'),
(27, 23, '_wp_trash_meta_time', '1621254518'),
(28, 24, '_edit_lock', '1621254825:1'),
(29, 24, '_wp_trash_meta_status', 'publish'),
(30, 24, '_wp_trash_meta_time', '1621254826'),
(31, 25, '_edit_lock', '1621255660:1'),
(32, 25, '_pingme', '1'),
(33, 25, '_encloseme', '1'),
(34, 29, '_edit_lock', '1621255578:1'),
(35, 29, '_wp_trash_meta_status', 'publish'),
(36, 29, '_wp_trash_meta_time', '1621255582'),
(37, 30, '_edit_lock', '1621255965:1'),
(38, 31, '_edit_lock', '1621255676:1'),
(39, 33, '_edit_lock', '1621255626:1'),
(40, 35, '_edit_lock', '1621255930:1'),
(41, 30, '_customize_restore_dismissed', '1'),
(42, 37, '_wp_trash_meta_status', 'publish'),
(43, 37, '_wp_trash_meta_time', '1621256018'),
(44, 1, '_wp_trash_meta_status', 'publish'),
(45, 1, '_wp_trash_meta_time', '1621256084'),
(46, 1, '_wp_desired_post_slug', 'hello-world'),
(47, 1, '_wp_trash_meta_comments_status', 'a:1:{i:1;s:1:\"1\";}'),
(48, 25, '_wp_trash_meta_status', 'publish'),
(49, 25, '_wp_trash_meta_time', '1621256085'),
(50, 25, '_wp_desired_post_slug', 'grafana-service'),
(51, 38, '_edit_lock', '1621256003:1'),
(52, 38, '_pingme', '1'),
(53, 38, '_encloseme', '1');

-- --------------------------------------------------------

--
-- Table structure for table `wp_posts`
--

CREATE TABLE `wp_posts` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `post_author` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `post_date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `post_date_gmt` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `post_content` longtext COLLATE utf8mb4_unicode_ci NOT NULL,
  `post_title` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `post_excerpt` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `post_status` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'publish',
  `comment_status` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'open',
  `ping_status` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'open',
  `post_password` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `post_name` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `to_ping` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `pinged` text COLLATE utf8mb4_unicode_ci NOT NULL,
  `post_modified` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `post_modified_gmt` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `post_content_filtered` longtext COLLATE utf8mb4_unicode_ci NOT NULL,
  `post_parent` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `guid` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `menu_order` int(11) NOT NULL DEFAULT '0',
  `post_type` varchar(20) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT 'post',
  `post_mime_type` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `comment_count` bigint(20) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_posts`
--

INSERT INTO `wp_posts` (`ID`, `post_author`, `post_date`, `post_date_gmt`, `post_content`, `post_title`, `post_excerpt`, `post_status`, `comment_status`, `ping_status`, `post_password`, `post_name`, `to_ping`, `pinged`, `post_modified`, `post_modified_gmt`, `post_content_filtered`, `post_parent`, `guid`, `menu_order`, `post_type`, `post_mime_type`, `comment_count`) VALUES
(1, 1, '2021-04-24 16:01:23', '2021-04-24 16:01:23', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'trash', 'open', 'open', '', 'hello-world__trashed', '', '', '2021-05-17 12:54:44', '2021-05-17 12:54:44', '', 0, 'http://192.168.99.101:5050/?p=1', 0, 'post', '', 1),
(2, 1, '2021-04-24 16:01:23', '2021-04-24 16:01:23', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s services project</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:quote -->\n<blockquote class=\"wp-block-quote\"><p>Hi there! I\'m a bike messenger by day, aspiring actor by night, and this is my website. I live in Los Angeles, have a great dog named Jack, and I like piña coladas. (And gettin\' caught in the rain.)</p></blockquote>\n<!-- /wp:quote -->\n\n<!-- wp:paragraph -->\n<p>...or something like this:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:quote -->\n<blockquote class=\"wp-block-quote\"><p>The XYZ Doohickey Company was founded in 1971, and has been providing quality doohickeys to the public ever since. Located in Gotham City, XYZ employs over 2,000 people and does all kinds of awesome things for the Gotham community.</p></blockquote>\n<!-- /wp:quote -->\n\n<!-- wp:paragraph -->\n<p>As a new WordPress user, you should go to <a href=\"http://192.168.99.101:5050/wp-admin/\">your dashboard</a> to delete this page and create new pages for your content. Have fun!</p>\n<!-- /wp:paragraph -->', 'Services project', '', 'publish', 'closed', 'open', '', 'sample-page', '', '', '2021-05-17 12:08:31', '2021-05-17 12:08:31', '', 0, 'http://192.168.99.101:5050/?page_id=2', 0, 'page', '', 0),
(3, 1, '2021-04-24 16:01:23', '2021-04-24 16:01:23', '<!-- wp:heading --><h2>Who we are</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>Our website address is: http://192.168.99.101:5050.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Comments</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>When visitors leave comments on the site we collect the data shown in the comments form, and also the visitor&#8217;s IP address and browser user agent string to help spam detection.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>An anonymized string created from your email address (also called a hash) may be provided to the Gravatar service to see if you are using it. The Gravatar service privacy policy is available here: https://automattic.com/privacy/. After approval of your comment, your profile picture is visible to the public in the context of your comment.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Media</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>If you upload images to the website, you should avoid uploading images with embedded location data (EXIF GPS) included. Visitors to the website can download and extract any location data from images on the website.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Cookies</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>If you leave a comment on our site you may opt-in to saving your name, email address and website in cookies. These are for your convenience so that you do not have to fill in your details again when you leave another comment. These cookies will last for one year.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>If you visit our login page, we will set a temporary cookie to determine if your browser accepts cookies. This cookie contains no personal data and is discarded when you close your browser.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>When you log in, we will also set up several cookies to save your login information and your screen display choices. Login cookies last for two days, and screen options cookies last for a year. If you select &quot;Remember Me&quot;, your login will persist for two weeks. If you log out of your account, the login cookies will be removed.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>If you edit or publish an article, an additional cookie will be saved in your browser. This cookie includes no personal data and simply indicates the post ID of the article you just edited. It expires after 1 day.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Embedded content from other websites</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>Articles on this site may include embedded content (e.g. videos, images, articles, etc.). Embedded content from other websites behaves in the exact same way as if the visitor has visited the other website.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>These websites may collect data about you, use cookies, embed additional third-party tracking, and monitor your interaction with that embedded content, including tracking your interaction with the embedded content if you have an account and are logged in to that website.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Who we share your data with</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>If you request a password reset, your IP address will be included in the reset email.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>How long we retain your data</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>If you leave a comment, the comment and its metadata are retained indefinitely. This is so we can recognize and approve any follow-up comments automatically instead of holding them in a moderation queue.</p><!-- /wp:paragraph --><!-- wp:paragraph --><p>For users that register on our website (if any), we also store the personal information they provide in their user profile. All users can see, edit, or delete their personal information at any time (except they cannot change their username). Website administrators can also see and edit that information.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>What rights you have over your data</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>If you have an account on this site, or have left comments, you can request to receive an exported file of the personal data we hold about you, including any data you have provided to us. You can also request that we erase any personal data we hold about you. This does not include any data we are obliged to keep for administrative, legal, or security purposes.</p><!-- /wp:paragraph --><!-- wp:heading --><h2>Where we send your data</h2><!-- /wp:heading --><!-- wp:paragraph --><p><strong class=\"privacy-policy-tutorial\">Suggested text: </strong>Visitor comments may be checked through an automated spam detection service.</p><!-- /wp:paragraph -->', 'Privacy Policy', '', 'draft', 'closed', 'open', '', 'privacy-policy', '', '', '2021-04-24 16:01:23', '2021-04-24 16:01:23', '', 0, 'http://192.168.99.101:5050/?page_id=3', 0, 'page', '', 0),
(4, 1, '2021-04-24 16:02:06', '0000-00-00 00:00:00', '', 'Auto Draft', '', 'auto-draft', 'open', 'open', '', '', '', '', '2021-04-24 16:02:06', '0000-00-00 00:00:00', '', 0, 'http://192.168.99.101:5050/?p=4', 0, 'post', '', 0),
(6, 1, '2021-05-17 11:05:46', '2021-05-17 11:05:46', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s services project</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:quote -->\n<blockquote class=\"wp-block-quote\"><p>Hi there! I\'m a bike messenger by day, aspiring actor by night, and this is my website. I live in Los Angeles, have a great dog named Jack, and I like piña coladas. (And gettin\' caught in the rain.)</p></blockquote>\n<!-- /wp:quote -->\n\n<!-- wp:paragraph -->\n<p>...or something like this:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:quote -->\n<blockquote class=\"wp-block-quote\"><p>The XYZ Doohickey Company was founded in 1971, and has been providing quality doohickeys to the public ever since. Located in Gotham City, XYZ employs over 2,000 people and does all kinds of awesome things for the Gotham community.</p></blockquote>\n<!-- /wp:quote -->\n\n<!-- wp:paragraph -->\n<p>As a new WordPress user, you should go to <a href=\"http://192.168.99.101:5050/wp-admin/\">your dashboard</a> to delete this page and create new pages for your content. Have fun!</p>\n<!-- /wp:paragraph -->', 'Services project', '', 'inherit', 'closed', 'closed', '', '2-revision-v1', '', '', '2021-05-17 11:05:46', '2021-05-17 11:05:46', '', 2, 'http://192.168.99.102:5050/?p=6', 0, 'revision', '', 0),
(7, 1, '2021-05-17 11:22:44', '2021-05-17 11:22:44', '<!-- wp:paragraph -->\n<p>Welcome to WordPress. This is your first post. Edit or delete it, then start writing!</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:22:44', '2021-05-17 11:22:44', '', 1, 'http://192.168.99.102:5050/?p=7', 0, 'revision', '', 0),
(9, 1, '2021-05-17 11:29:53', '2021-05-17 11:29:53', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http:/192.168.99.102/\" data-type=\"URL\" data-id=\"http:/192.168.99.102/\">http:/192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:cover {\"overlayColor\":\"green\",\"contentPosition\":\"center center\",\"align\":\"wide\",\"className\":\"is-style-twentytwentyone-border\"} -->\n<div class=\"wp-block-cover alignwide has-green-background-color has-background-dim is-style-twentytwentyone-border\"><div class=\"wp-block-cover__inner-container\"><!-- wp:spacer {\"height\":20} -->\n<div style=\"height:20px\" aria-hidden=\"true\" class=\"wp-block-spacer\"></div>\n<!-- /wp:spacer -->\n\n<!-- wp:paragraph {\"fontSize\":\"huge\"} -->\n<p class=\"has-huge-font-size\">Let’s Connect.</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:spacer {\"height\":75} -->\n<div style=\"height:75px\" aria-hidden=\"true\" class=\"wp-block-spacer\"></div>\n<!-- /wp:spacer -->\n\n<!-- wp:columns -->\n<div class=\"wp-block-columns\"><!-- wp:column -->\n<div class=\"wp-block-column\"><!-- wp:paragraph -->\n<p><a href=\"#\" data-type=\"URL\">Twitter</a> / <a href=\"#\" data-type=\"URL\">Instagram</a> / <a href=\"#\" data-type=\"URL\">Dribbble</a></p>\n<!-- /wp:paragraph --></div>\n<!-- /wp:column -->\n\n<!-- wp:column -->\n<div class=\"wp-block-column\"><!-- wp:paragraph -->\n<p><a href=\"#\">example@example.com</a></p>\n<!-- /wp:paragraph --></div>\n<!-- /wp:column --></div>\n<!-- /wp:columns -->\n\n<!-- wp:spacer {\"height\":20} -->\n<div style=\"height:20px\" aria-hidden=\"true\" class=\"wp-block-spacer\"></div>\n<!-- /wp:spacer --></div></div>\n<!-- /wp:cover -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:29:53', '2021-05-17 11:29:53', '', 1, 'http://192.168.99.102:5050/?p=9', 0, 'revision', '', 0),
(10, 1, '2021-05-17 11:32:32', '2021-05-17 11:32:32', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:32:32', '2021-05-17 11:32:32', '', 1, 'http://192.168.99.102:5050/?p=10', 0, 'revision', '', 0),
(11, 1, '2021-05-17 11:34:25', '2021-05-17 11:34:25', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>as</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:34:25', '2021-05-17 11:34:25', '', 1, 'http://192.168.99.102:5050/?p=11', 0, 'revision', '', 0),
(13, 1, '2021-05-17 11:39:18', '2021-05-17 11:39:18', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a> redirect to<a href=\"http://192.168.99.102:5050\"> http://192.168.99.102:5050</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102/phpmyadmin/\">http://192.168.99.102/phpmyadmin/ redirected to http://192.168.99.102:5000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>as</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:39:18', '2021-05-17 11:39:18', '', 1, 'http://192.168.99.102:5050/?p=13', 0, 'revision', '', 0),
(14, 1, '2021-05-17 11:40:17', '2021-05-17 11:40:17', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a> redirect to<a href=\"http://192.168.99.102:5050\"> http://192.168.99.102:5050</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a> redirected to <a href=\"http://192.168.99.102:5000/\">http://192.168.99.102:5000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>as</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:40:17', '2021-05-17 11:40:17', '', 1, 'http://192.168.99.102:5050/?p=14', 0, 'revision', '', 0),
(15, 1, '2021-05-17 11:40:48', '2021-05-17 11:40:48', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a> redirect to <a href=\"http://192.168.99.102:5050\">http://192.168.99.102:5050</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a> redirected to <a href=\"http://192.168.99.102:5000/\">http://192.168.99.102:5000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>sa</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 11:40:48', '2021-05-17 11:40:48', '', 1, 'http://192.168.99.102:5050/?p=15', 0, 'revision', '', 0),
(16, 1, '2021-05-17 12:03:01', '2021-05-17 12:03:01', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>as</p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 12:03:01', '2021-05-17 12:03:01', '', 1, 'http://192.168.99.102:5050/?p=16', 0, 'revision', '', 0),
(17, 1, '2021-05-17 12:05:06', '2021-05-17 12:05:06', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 12:05:06', '2021-05-17 12:05:06', '', 1, 'http://192.168.99.102:5050/?p=17', 0, 'revision', '', 0),
(18, 1, '2021-05-17 12:14:04', '2021-05-17 12:14:04', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-autosave-v1', '', '', '2021-05-17 12:14:04', '2021-05-17 12:14:04', '', 1, 'http://192.168.99.102:5050/?p=18', 0, 'revision', '', 0),
(19, 1, '2021-05-17 12:14:07', '2021-05-17 12:14:07', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'SERVICE PROJECT', '', 'inherit', 'closed', 'closed', '', '1-revision-v1', '', '', '2021-05-17 12:14:07', '2021-05-17 12:14:07', '', 1, 'http://192.168.99.102:5050/?p=19', 0, 'revision', '', 0),
(20, 1, '2021-05-17 12:19:52', '2021-05-17 12:19:52', '{\n    \"blogname\": {\n        \"value\": \"yeschall\'s services\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:18:53\"\n    },\n    \"blogdescription\": {\n        \"value\": \"\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:18:53\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section1_title]\": {\n        \"value\": \"I\'m here\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:19:52\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section1_desc]\": {\n        \"value\": \"fsfasfasfdasfasf\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:19:52\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', '65af27e8-ff3c-4c5e-a3a5-f1c5358c0fc6', '', '', '2021-05-17 12:19:52', '2021-05-17 12:19:52', '', 0, 'http://192.168.99.102:5050/?p=20', 0, 'customize_changeset', '', 0),
(21, 1, '2021-05-17 12:25:14', '2021-05-17 12:25:14', '{\n    \"thinkup_redux_variables[thinkup_homepage_section1_title]\": {\n        \"value\": \"Check Page\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:24:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section1_desc]\": {\n        \"value\": \"Click below to open the page\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:21:25\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section1_link]\": {\n        \"value\": \"2\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:25:14\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section2_desc]\": {\n        \"value\": \"Click below to open the page\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:22:25\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section3_desc]\": {\n        \"value\": \"Click below to open the page\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:22:25\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section2_title]\": {\n        \"value\": \"PHPMyAdmin\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:24:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section3_title]\": {\n        \"value\": \"Grafana\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:24:45\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', '933224de-f920-4f66-a198-4093097b150a', '', '', '2021-05-17 12:25:14', '2021-05-17 12:25:14', '', 0, 'http://192.168.99.102:5050/?p=21', 0, 'customize_changeset', '', 0),
(22, 1, '2021-05-17 12:27:42', '2021-05-17 12:27:42', '{\n    \"thinkup_redux_variables[thinkup_homepage_sliderswitch]\": {\n        \"value\": \"option3\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:27:42\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_sliderimage1_title]\": {\n        \"value\": \"title\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:26:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_sliderimage1_desc]\": {\n        \"value\": \"asdfasdf\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:26:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_sliderimage1_link]\": {\n        \"value\": \"2\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:26:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_introswitch]\": {\n        \"value\": false,\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:26:45\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_layout]\": {\n        \"value\": \"option1\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:27:42\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_introactionlink]\": {\n        \"value\": \"option3\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:27:42\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', '389f8483-d082-4fb8-8380-4a978af10367', '', '', '2021-05-17 12:27:42', '2021-05-17 12:27:42', '', 0, 'http://192.168.99.102:5050/?p=22', 0, 'customize_changeset', '', 0),
(23, 1, '2021-05-17 12:28:38', '2021-05-17 12:28:38', '{\n    \"thinkup_redux_variables[thinkup_homepage_sliderswitch]\": {\n        \"value\": \"option3\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:28:38\"\n    },\n    \"thinkup_redux_variables[thinkup_blog_layout]\": {\n        \"value\": \"option1\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:28:38\"\n    },\n    \"thinkup_redux_variables[thinkup_blog_postswitch]\": {\n        \"value\": \"option3\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:28:38\"\n    },\n    \"thinkup_redux_variables[thinkup_post_layout]\": {\n        \"value\": \"option1\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:28:38\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', 'cca5d4f2-3790-43f5-9bab-846c64a4ec60', '', '', '2021-05-17 12:28:38', '2021-05-17 12:28:38', '', 0, 'http://192.168.99.102:5050/?p=23', 0, 'customize_changeset', '', 0),
(24, 1, '2021-05-17 12:33:46', '2021-05-17 12:33:46', '{\n    \"thinkup_redux_variables[thinkup_general_layout]\": {\n        \"value\": \"option1\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:29:45\"\n    },\n    \"thinkup_redux_variables[thinkup_footer_layout]\": {\n        \"value\": \"option1\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:31:45\"\n    },\n    \"thinkup_redux_variables[thinkup_footer_widgetswitch]\": {\n        \"value\": true,\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:32:45\"\n    },\n    \"minamaze::background_color\": {\n        \"value\": \"#cecece\",\n        \"type\": \"theme_mod\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:30:45\"\n    },\n    \"minamaze::nav_menu_locations[pre_header_menu]\": {\n        \"value\": 0,\n        \"type\": \"theme_mod\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:31:45\"\n    },\n    \"nav_menu[-584137708202340400]\": {\n        \"value\": false,\n        \"type\": \"nav_menu\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:31:45\"\n    },\n    \"sidebars_widgets[footer-w1]\": {\n        \"value\": [],\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:32:45\"\n    },\n    \"widget_custom_html[3]\": {\n        \"value\": {\n            \"encoded_serialized_instance\": \"YToyOntzOjU6InRpdGxlIjtzOjg6ImFzZGZhc2RmIjtzOjc6ImNvbnRlbnQiO3M6MDoiIjt9\",\n            \"title\": \"asdfasdf\",\n            \"is_widget_customizer_js_value\": true,\n            \"instance_hash_key\": \"3508247d7d9b9d2cf4a5dbb39e196119\"\n        },\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:31:45\"\n    },\n    \"show_on_front\": {\n        \"value\": \"posts\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:33:45\"\n    },\n    \"page_on_front\": {\n        \"value\": \"0\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:32:45\"\n    },\n    \"blogname\": {\n        \"value\": \"Yeschall\'s services\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:33:45\"\n    },\n    \"blogdescription\": {\n        \"value\": \"\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:33:45\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', 'ab33a25a-a52a-4bf6-a44a-b058d38cff07', '', '', '2021-05-17 12:33:46', '2021-05-17 12:33:46', '', 0, 'http://192.168.99.102:5050/?p=24', 0, 'customize_changeset', '', 0),
(25, 1, '2021-05-17 12:42:34', '2021-05-17 12:42:34', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Grafana service is  interactive visualization web application. <br>Click <a href=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\" data-type=\"URL\" data-id=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\">here</a> for check:<br></p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'trash', 'open', 'open', '', 'grafana-service__trashed', '', '', '2021-05-17 12:54:45', '2021-05-17 12:54:45', '', 0, 'http://192.168.99.102:5050/?p=25', 0, 'post', '', 0),
(26, 1, '2021-05-17 12:35:38', '2021-05-17 12:35:38', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p></p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'inherit', 'closed', 'closed', '', '25-revision-v1', '', '', '2021-05-17 12:35:38', '2021-05-17 12:35:38', '', 25, 'http://192.168.99.102:5050/?p=26', 0, 'revision', '', 0),
(27, 1, '2021-05-17 12:39:40', '2021-05-17 12:39:40', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Grafana service is  interactive visualization web application.</p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'inherit', 'closed', 'closed', '', '25-revision-v1', '', '', '2021-05-17 12:39:40', '2021-05-17 12:39:40', '', 25, 'http://192.168.99.102:5050/?p=27', 0, 'revision', '', 0),
(28, 1, '2021-05-17 12:42:34', '2021-05-17 12:42:34', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Grafana service is  interactive visualization web application. <br>Click <a href=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\" data-type=\"URL\" data-id=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\">here</a> for check:<br></p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'inherit', 'closed', 'closed', '', '25-revision-v1', '', '', '2021-05-17 12:42:34', '2021-05-17 12:42:34', '', 25, 'http://192.168.99.102:5050/?p=28', 0, 'revision', '', 0),
(29, 1, '2021-05-17 12:46:22', '2021-05-17 12:46:22', '{\n    \"thinkup_redux_variables[thinkup_homepage_section1_desc]\": {\n        \"value\": \"Click below to open the page\\n<a href=\\\"ya.ru\\\">\\nya\\n</a>\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:46:18\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', '284faff2-0afe-45f2-91c4-5533acee9ddd', '', '', '2021-05-17 12:46:22', '2021-05-17 12:46:22', '', 0, 'http://192.168.99.102:5050/?p=29', 0, 'customize_changeset', '', 0),
(30, 1, '2021-05-17 12:46:37', '0000-00-00 00:00:00', '{\n    \"thinkup_redux_variables[thinkup_homepage_section1_desc]\": {\n        \"value\": \"Click below to open the page\\n\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:46:37\"\n    }\n}', '', '', 'auto-draft', 'closed', 'closed', '', 'a7d02251-07f7-4afa-a4a6-0bd5ec31c468', '', '', '2021-05-17 12:46:37', '0000-00-00 00:00:00', '', 0, 'http://192.168.99.102:5050/?p=30', 0, 'customize_changeset', '', 0),
(31, 1, '2021-05-17 12:47:55', '2021-05-17 12:47:55', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Grafana service is  interactive visualization web application.<br>Click <a href=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\">here</a> for check:</p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'publish', 'closed', 'closed', '', 'grafana-service', '', '', '2021-05-17 12:47:55', '2021-05-17 12:47:55', '', 0, 'http://192.168.99.102:5050/?page_id=31', 0, 'page', '', 0),
(32, 1, '2021-05-17 12:47:55', '2021-05-17 12:47:55', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"https://www.influxdata.com/wp-content/uploads/Grafana.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Grafana service is  interactive visualization web application.<br>Click <a href=\"http://192.168.99.102:3000/d/ubBcolCMz/services-dashboard?orgId=1&amp;from=now-5m&amp;to=now\">here</a> for check:</p>\n<!-- /wp:paragraph -->', 'Grafana Service', '', 'inherit', 'closed', 'closed', '', '31-revision-v1', '', '', '2021-05-17 12:47:55', '2021-05-17 12:47:55', '', 31, 'http://192.168.99.102:5050/?p=32', 0, 'revision', '', 0),
(33, 1, '2021-05-17 12:49:23', '2021-05-17 12:49:23', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->', 'Checking Page', '', 'publish', 'closed', 'closed', '', 'checking-page', '', '', '2021-05-17 12:49:23', '2021-05-17 12:49:23', '', 0, 'http://192.168.99.102:5050/?page_id=33', 0, 'page', '', 0),
(34, 1, '2021-05-17 12:49:23', '2021-05-17 12:49:23', '<!-- wp:paragraph -->\n<p>Welcome to yeschall\'s service project page:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p>You can visit the following pages:</p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a rel=\"noreferrer noopener\" href=\"https://192.168.99.102/\" target=\"_blank\">https://192.168.99.102/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102:443/\">https://192.168.99.102:443/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/wordpress/\">https://192.168.99.102/wordpress/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"https://192.168.99.102/phpmyadmin/\">https://192.168.99.102/phpmyadmin/</a></p>\n<!-- /wp:paragraph -->\n\n<!-- wp:paragraph -->\n<p><a href=\"http://192.168.99.102:3000/\">http://192.168.99.102:3000/</a></p>\n<!-- /wp:paragraph -->', 'Checking Page', '', 'inherit', 'closed', 'closed', '', '33-revision-v1', '', '', '2021-05-17 12:49:23', '2021-05-17 12:49:23', '', 33, 'http://192.168.99.102:5050/?p=34', 0, 'revision', '', 0),
(35, 1, '2021-05-17 12:51:46', '2021-05-17 12:51:46', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"http://toplogos.ru/images/logo-phpmyadmin.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Click <a href=\"http://192.168.99.102:5000/\">here</a> to check</p>\n<!-- /wp:paragraph -->', 'phpMyAdmin Service', '', 'publish', 'closed', 'closed', '', 'phpmyadmin-service', '', '', '2021-05-17 12:51:46', '2021-05-17 12:51:46', '', 0, 'http://192.168.99.102:5050/?page_id=35', 0, 'page', '', 0),
(36, 1, '2021-05-17 12:51:46', '2021-05-17 12:51:46', '<!-- wp:image {\"sizeSlug\":\"large\"} -->\n<figure class=\"wp-block-image size-large\"><img src=\"http://toplogos.ru/images/logo-phpmyadmin.png\" alt=\"\"/></figure>\n<!-- /wp:image -->\n\n<!-- wp:paragraph -->\n<p>Click <a href=\"http://192.168.99.102:5000/\">here</a> to check</p>\n<!-- /wp:paragraph -->', 'phpMyAdmin Service', '', 'inherit', 'closed', 'closed', '', '35-revision-v1', '', '', '2021-05-17 12:51:46', '2021-05-17 12:51:46', '', 35, 'http://192.168.99.102:5050/?p=36', 0, 'revision', '', 0),
(37, 1, '2021-05-17 12:53:38', '2021-05-17 12:53:38', '{\n    \"thinkup_redux_variables[thinkup_homepage_section1_link]\": {\n        \"value\": \"33\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:53:38\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section2_title]\": {\n        \"value\": \"phpMyAdmin\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:53:38\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section2_link]\": {\n        \"value\": \"35\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:53:38\"\n    },\n    \"thinkup_redux_variables[thinkup_homepage_section3_link]\": {\n        \"value\": \"31\",\n        \"type\": \"option\",\n        \"user_id\": 1,\n        \"date_modified_gmt\": \"2021-05-17 12:53:38\"\n    }\n}', '', '', 'trash', 'closed', 'closed', '', '5e114d46-3695-4195-9418-f50e6886ddb6', '', '', '2021-05-17 12:53:38', '2021-05-17 12:53:38', '', 0, 'http://192.168.99.102:5050/?p=37', 0, 'customize_changeset', '', 0),
(38, 1, '2021-05-17 12:55:54', '2021-05-17 12:55:54', '<!-- wp:paragraph -->\n<p>It is a default post to check</p>\n<!-- /wp:paragraph -->', 'Sample Post', '', 'publish', 'open', 'open', '', 'sample-post', '', '', '2021-05-17 12:55:54', '2021-05-17 12:55:54', '', 0, 'http://192.168.99.102:5050/?p=38', 0, 'post', '', 0),
(39, 1, '2021-05-17 12:55:54', '2021-05-17 12:55:54', '<!-- wp:paragraph -->\n<p>It is a default post to check</p>\n<!-- /wp:paragraph -->', 'Sample Post', '', 'inherit', 'closed', 'closed', '', '38-revision-v1', '', '', '2021-05-17 12:55:54', '2021-05-17 12:55:54', '', 38, 'http://192.168.99.102:5050/?p=39', 0, 'revision', '', 0);

-- --------------------------------------------------------

--
-- Table structure for table `wp_termmeta`
--

CREATE TABLE `wp_termmeta` (
  `meta_id` bigint(20) UNSIGNED NOT NULL,
  `term_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `meta_key` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `meta_value` longtext COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- --------------------------------------------------------

--
-- Table structure for table `wp_terms`
--

CREATE TABLE `wp_terms` (
  `term_id` bigint(20) UNSIGNED NOT NULL,
  `name` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `slug` varchar(200) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `term_group` bigint(10) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_terms`
--

INSERT INTO `wp_terms` (`term_id`, `name`, `slug`, `term_group`) VALUES
(1, 'Uncategorized', 'uncategorized', 0);

-- --------------------------------------------------------

--
-- Table structure for table `wp_term_relationships`
--

CREATE TABLE `wp_term_relationships` (
  `object_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `term_taxonomy_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `term_order` int(11) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_term_relationships`
--

INSERT INTO `wp_term_relationships` (`object_id`, `term_taxonomy_id`, `term_order`) VALUES
(1, 1, 0),
(25, 1, 0),
(38, 1, 0);

-- --------------------------------------------------------

--
-- Table structure for table `wp_term_taxonomy`
--

CREATE TABLE `wp_term_taxonomy` (
  `term_taxonomy_id` bigint(20) UNSIGNED NOT NULL,
  `term_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `taxonomy` varchar(32) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `description` longtext COLLATE utf8mb4_unicode_ci NOT NULL,
  `parent` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `count` bigint(20) NOT NULL DEFAULT '0'
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_term_taxonomy`
--

INSERT INTO `wp_term_taxonomy` (`term_taxonomy_id`, `term_id`, `taxonomy`, `description`, `parent`, `count`) VALUES
(1, 1, 'category', '', 0, 1);

-- --------------------------------------------------------

--
-- Table structure for table `wp_usermeta`
--

CREATE TABLE `wp_usermeta` (
  `umeta_id` bigint(20) UNSIGNED NOT NULL,
  `user_id` bigint(20) UNSIGNED NOT NULL DEFAULT '0',
  `meta_key` varchar(255) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `meta_value` longtext COLLATE utf8mb4_unicode_ci
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_usermeta`
--

INSERT INTO `wp_usermeta` (`umeta_id`, `user_id`, `meta_key`, `meta_value`) VALUES
(1, 1, 'nickname', 'admin'),
(2, 1, 'first_name', ''),
(3, 1, 'last_name', ''),
(4, 1, 'description', ''),
(5, 1, 'rich_editing', 'true'),
(6, 1, 'syntax_highlighting', 'true'),
(7, 1, 'comment_shortcuts', 'false'),
(8, 1, 'admin_color', 'fresh'),
(9, 1, 'use_ssl', '0'),
(10, 1, 'show_admin_bar_front', 'true'),
(11, 1, 'locale', ''),
(12, 1, 'wp_capabilities', 'a:1:{s:13:\"administrator\";b:1;}'),
(13, 1, 'wp_user_level', '10'),
(14, 1, 'dismissed_wp_pointers', 'theme_editor_notice'),
(15, 1, 'show_welcome_panel', '1'),
(16, 1, 'session_tokens', 'a:1:{s:64:\"5d7a830fdd4e63d1772044c30c5e769b0283c1dad45f6e2423dc7fb0a7096058\";a:4:{s:10:\"expiration\";i:1621421539;s:2:\"ip\";s:10:\"172.17.0.1\";s:2:\"ua\";s:121:\"Mozilla/5.0 (Macintosh; Intel Mac OS X 10_14_6) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/88.0.4324.150 Safari/537.36\";s:5:\"login\";i:1621248739;}}'),
(17, 1, 'wp_dashboard_quick_press_last_post_id', '4'),
(18, 1, 'community-events-location', 'a:1:{s:2:\"ip\";s:10:\"172.17.0.0\";}'),
(19, 2, 'nickname', 'user1'),
(20, 2, 'first_name', 'user1'),
(21, 2, 'last_name', 'user1_surname'),
(22, 2, 'description', ''),
(23, 2, 'rich_editing', 'true'),
(24, 2, 'syntax_highlighting', 'true'),
(25, 2, 'comment_shortcuts', 'false'),
(26, 2, 'admin_color', 'fresh'),
(27, 2, 'use_ssl', '0'),
(28, 2, 'show_admin_bar_front', 'true'),
(29, 2, 'locale', ''),
(30, 2, 'wp_capabilities', 'a:1:{s:10:\"subscriber\";b:1;}'),
(31, 2, 'wp_user_level', '0'),
(32, 2, 'dismissed_wp_pointers', ''),
(33, 3, 'nickname', 'user2'),
(34, 3, 'first_name', 'user2'),
(35, 3, 'last_name', 'user2_surname'),
(36, 3, 'description', ''),
(37, 3, 'rich_editing', 'true'),
(38, 3, 'syntax_highlighting', 'true'),
(39, 3, 'comment_shortcuts', 'false'),
(40, 3, 'admin_color', 'fresh'),
(41, 3, 'use_ssl', '0'),
(42, 3, 'show_admin_bar_front', 'true'),
(43, 3, 'locale', ''),
(44, 3, 'wp_capabilities', 'a:1:{s:6:\"editor\";b:1;}'),
(45, 3, 'wp_user_level', '7'),
(46, 3, 'dismissed_wp_pointers', ''),
(47, 1, 'wp_user-settings', 'libraryContent=upload'),
(48, 1, 'wp_user-settings-time', '1621253798'),
(49, 1, 'managenav-menuscolumnshidden', 'a:5:{i:0;s:11:\"link-target\";i:1;s:11:\"css-classes\";i:2;s:3:\"xfn\";i:3;s:11:\"description\";i:4;s:15:\"title-attribute\";}'),
(50, 1, 'metaboxhidden_nav-menus', 'a:1:{i:0;s:12:\"add-post_tag\";}');

-- --------------------------------------------------------

--
-- Table structure for table `wp_users`
--

CREATE TABLE `wp_users` (
  `ID` bigint(20) UNSIGNED NOT NULL,
  `user_login` varchar(60) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_pass` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_nicename` varchar(50) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_email` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_url` varchar(100) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_registered` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `user_activation_key` varchar(255) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT '',
  `user_status` int(11) NOT NULL DEFAULT '0',
  `display_name` varchar(250) COLLATE utf8mb4_unicode_ci NOT NULL DEFAULT ''
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Dumping data for table `wp_users`
--

INSERT INTO `wp_users` (`ID`, `user_login`, `user_pass`, `user_nicename`, `user_email`, `user_url`, `user_registered`, `user_activation_key`, `user_status`, `display_name`) VALUES
(1, 'admin', '$P$BQB8tAAaqQJGhGhhlQkbPbtZy5kZum/', 'admin', 'aaa@mail.com', 'http://192.168.99.101:5050', '2021-04-24 16:01:23', '', 0, 'admin'),
(2, 'user1', '$P$BBiX76HRbghwOXpcR7XYwNn8AnDKJd1', 'user1', 'user1@gmail.com', '', '2021-05-17 10:53:13', '', 0, 'user1 user1_surname'),
(3, 'user2', '$P$BTTKEOghRgf.HoI9ZVOI/0f7zF2JbT/', 'user2', 'user2@gmail.com', '', '2021-05-17 10:54:13', '', 0, 'user2 user2_surname');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `wp_commentmeta`
--
ALTER TABLE `wp_commentmeta`
  ADD PRIMARY KEY (`meta_id`),
  ADD KEY `comment_id` (`comment_id`),
  ADD KEY `meta_key` (`meta_key`(191));

--
-- Indexes for table `wp_comments`
--
ALTER TABLE `wp_comments`
  ADD PRIMARY KEY (`comment_ID`),
  ADD KEY `comment_post_ID` (`comment_post_ID`),
  ADD KEY `comment_approved_date_gmt` (`comment_approved`,`comment_date_gmt`),
  ADD KEY `comment_date_gmt` (`comment_date_gmt`),
  ADD KEY `comment_parent` (`comment_parent`),
  ADD KEY `comment_author_email` (`comment_author_email`(10));

--
-- Indexes for table `wp_links`
--
ALTER TABLE `wp_links`
  ADD PRIMARY KEY (`link_id`),
  ADD KEY `link_visible` (`link_visible`);

--
-- Indexes for table `wp_options`
--
ALTER TABLE `wp_options`
  ADD PRIMARY KEY (`option_id`),
  ADD UNIQUE KEY `option_name` (`option_name`),
  ADD KEY `autoload` (`autoload`);

--
-- Indexes for table `wp_postmeta`
--
ALTER TABLE `wp_postmeta`
  ADD PRIMARY KEY (`meta_id`),
  ADD KEY `post_id` (`post_id`),
  ADD KEY `meta_key` (`meta_key`(191));

--
-- Indexes for table `wp_posts`
--
ALTER TABLE `wp_posts`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `post_name` (`post_name`(191)),
  ADD KEY `type_status_date` (`post_type`,`post_status`,`post_date`,`ID`),
  ADD KEY `post_parent` (`post_parent`),
  ADD KEY `post_author` (`post_author`);

--
-- Indexes for table `wp_termmeta`
--
ALTER TABLE `wp_termmeta`
  ADD PRIMARY KEY (`meta_id`),
  ADD KEY `term_id` (`term_id`),
  ADD KEY `meta_key` (`meta_key`(191));

--
-- Indexes for table `wp_terms`
--
ALTER TABLE `wp_terms`
  ADD PRIMARY KEY (`term_id`),
  ADD KEY `slug` (`slug`(191)),
  ADD KEY `name` (`name`(191));

--
-- Indexes for table `wp_term_relationships`
--
ALTER TABLE `wp_term_relationships`
  ADD PRIMARY KEY (`object_id`,`term_taxonomy_id`),
  ADD KEY `term_taxonomy_id` (`term_taxonomy_id`);

--
-- Indexes for table `wp_term_taxonomy`
--
ALTER TABLE `wp_term_taxonomy`
  ADD PRIMARY KEY (`term_taxonomy_id`),
  ADD UNIQUE KEY `term_id_taxonomy` (`term_id`,`taxonomy`),
  ADD KEY `taxonomy` (`taxonomy`);

--
-- Indexes for table `wp_usermeta`
--
ALTER TABLE `wp_usermeta`
  ADD PRIMARY KEY (`umeta_id`),
  ADD KEY `user_id` (`user_id`),
  ADD KEY `meta_key` (`meta_key`(191));

--
-- Indexes for table `wp_users`
--
ALTER TABLE `wp_users`
  ADD PRIMARY KEY (`ID`),
  ADD KEY `user_login_key` (`user_login`),
  ADD KEY `user_nicename` (`user_nicename`),
  ADD KEY `user_email` (`user_email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `wp_commentmeta`
--
ALTER TABLE `wp_commentmeta`
  MODIFY `meta_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `wp_comments`
--
ALTER TABLE `wp_comments`
  MODIFY `comment_ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `wp_links`
--
ALTER TABLE `wp_links`
  MODIFY `link_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `wp_options`
--
ALTER TABLE `wp_options`
  MODIFY `option_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=229;

--
-- AUTO_INCREMENT for table `wp_postmeta`
--
ALTER TABLE `wp_postmeta`
  MODIFY `meta_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=54;

--
-- AUTO_INCREMENT for table `wp_posts`
--
ALTER TABLE `wp_posts`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=40;

--
-- AUTO_INCREMENT for table `wp_termmeta`
--
ALTER TABLE `wp_termmeta`
  MODIFY `meta_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `wp_terms`
--
ALTER TABLE `wp_terms`
  MODIFY `term_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `wp_term_taxonomy`
--
ALTER TABLE `wp_term_taxonomy`
  MODIFY `term_taxonomy_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=2;

--
-- AUTO_INCREMENT for table `wp_usermeta`
--
ALTER TABLE `wp_usermeta`
  MODIFY `umeta_id` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=51;

--
-- AUTO_INCREMENT for table `wp_users`
--
ALTER TABLE `wp_users`
  MODIFY `ID` bigint(20) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
