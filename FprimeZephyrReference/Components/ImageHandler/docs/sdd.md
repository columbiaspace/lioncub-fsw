# Components::ImageHandler

Receives images from the camera, and stores them on the file system for later use

## Usage Examples
Add usage examples here

### Diagrams
Add diagrams here

### Typical Usage
And the typical usage of the component here

## Class Diagram
Add a class diagram here

## Port Descriptions
| Name | Description |
|cmdIn|receive commands|
|cmdResponseOut|replying to commands|
|sendFile|---|
|receiveFile|---|
|imageReceive|receive image from the camera|

## Component States
Add component states in the chart below
| Name | Description |
|---|---|
|---|---|

## Sequence Diagrams
Add sequence diagrams here

## Parameters
| Name | Description |
|midSize|halfsize image|
|smallSize|smallest size image|

## Commands
| Name | Description |
|delete|which image to delete|
|downlink|which image , what size|
|list|go through all images|


## Events
| Name | Description |
|ReceivedImage|---|
|ReceivedDownlink request|---|
|ProcessImage|---|
|Confirmation|delete success, image status|

## Telemetry
| Name | Description |
|TotalSize|space being used|
|NumberOfImagesCurrent|---|
|TotalImagesTaken|---|

## Unit Tests
Add unit test descriptions in the chart below
| Name | Description | Output | Coverage |
|---|---|---|---|
|---|---|---|---|

## Requirements
Add requirements in the chart below
| Name | Description | Validation |
|---|---|---|
|---|---|---|

## Change Log
| Date | Description |
|---|---|
|---| Initial Draft |
