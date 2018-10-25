export interface IPoint {
    x: number;
    y: number;
}

export class Rect {
    top: number;
    right: number;
    bottom: number;
    left: number;

    constructor(top: number = 0, right: number = 0, bottom: number = 0, left: number = 0) {
        this.top = top;
        this.right = right;
        this.bottom = bottom;
        this.left = left;
    }

    union(otherRect: Rect) {
        this.top = Math.min(this.top, otherRect.top);
        this.left = Math.min(this.left, otherRect.left);
        this.bottom = Math.max(this.bottom, otherRect.bottom);
        this.right = Math.max(this.right, otherRect.right);
    }

    isInside(point: IPoint): boolean {
        return point.x >= this.left && point.x <= this.right && point.y >= this.top && point.y <= this.bottom;
    }

    get width(): number {
        return this.right - this.left;
    }

    get height(): number {
        return this.bottom - this.top;
    }
}