library(tryClass)

rcpp_hello_world()

smdt <- try_wrap_samdata()
smdt
sid <- samId(smdt)
sid