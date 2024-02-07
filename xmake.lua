add_rules("mode.debug", "mode.release")

set_languages("clatest")

if is_mode("release") then
    set_optimize("fastest")
end

set_warnings("allextra")

target("ZLibMaths")
    set_kind("shared")
    add_files("src/**.c")
    add_includedirs("include")