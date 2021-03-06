--- libgeda/src/scheme_object.c.orig
+++ libgeda/src/scheme_object.c
@@ -1986,8 +1986,8 @@
  * \param filename_s  New filename for \a obj_s.
  * \return \a obj_s.
  */
-SCM_DEFINE (set_picture_data_vector_x, "%set-picture-data/vector!",
-            3, 0, 0, (SCM obj_s, SCM data_s, SCM filename_s),
+SCM_DEFINE (set_picture_data_vector_x, "%set-picture-data/vector!", 3, 0, 0,
+            (SCM obj_s, SCM data_s, SCM filename_s),
             "Set a picture object's data from a vector.")
 {
   SCM vec_s = scm_any_to_s8vector (data_s);
