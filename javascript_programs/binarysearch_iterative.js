function binarySearch(arr, x)
{ 
	let l = 0;
	let r = arr.length - 1;
	let mid;
	while (r >= l) 
    {
		mid = l + Math.floor((r - l) / 2);
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

	arr =new Array(2, 3, 4, 10, 40);
	x = 10;
	n = arr.length;
	result = binarySearch(arr, x);
	
(result == -1) ? console.log("Element is not present in array") : console.log ("Element is present at index " + result);

