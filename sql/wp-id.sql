

update `wp_posts` set `id` = 1 where `id` = 0;
update `wp_term_relationships` set `object_id` = 1 where `object_id` = 0;
update `wp_postmeta` set `post_id` = 1 where `post_id` = 0;
update `wp_comments` set `comment_post_ID` = 1 where `comment_post_ID` = 0;

set @id_num = 0;
select @nums := (select count(*) from `wp_posts`);

while @id_num < @nums
    begin
        select @min_id := (SELECT min(id) FROM `wp_posts` where id between @id_num and 100);

        select id from `wp_posts` where id = @min_id;

        update `wp_posts` set `id` = id_num where `id` = min_id;
        update `wp_term_relationships` set `object_id` = id_num where `object_id` = min_id;
        update `wp_postmeta` set `post_id` = id_num where `post_id` = min_id;
        update `wp_comments` set `comment_post_ID` = id_num where `comment_post_ID` = min_id;

        set @id_num = @id_num + 1
    end
