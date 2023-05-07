$cppFiles = Get-ChildItem -Path .\src -Recurse -Include *.cpp,*.h

foreach ($file in $cppFiles) {
    $fileName = $file.FullName
    Write-Host "Formatting file: $fileName"
    clang-format -i $file.FullName
}
