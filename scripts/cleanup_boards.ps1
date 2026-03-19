# Elimina todos los boards excepto otto-robot-pet, otto-robot y common
$boardsPath = Join-Path $PSScriptRoot "..\main\boards"
$keep = @("common", "otto-robot", "otto-robot-pet")

Get-ChildItem -Path $boardsPath -Directory | ForEach-Object {
    if ($keep -notcontains $_.Name) {
        Write-Host "Eliminando: $($_.FullName)"
        Remove-Item -Path $_.FullName -Recurse -Force
    }
}

Write-Host "Limpieza completada. Boards restantes: common, otto-robot, otto-robot-pet"
